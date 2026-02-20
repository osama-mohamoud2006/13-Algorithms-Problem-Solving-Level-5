#include <queue>
#include <stack>
#include "../10-OOP Concepts/Project 3/clsDate.h"
#include <string>
class InterfaceQueueLine
{
public:
    virtual void IssueTicket() = 0;
    virtual void ServeNextClient() = 0;
    virtual void PrintTicketsLineRtl() = 0;
    virtual void PrintTicketsLineLtr() = 0;
    virtual void PrintInfo() = 0;
    virtual void PrintAllTickets() = 0;
};

class clsQueueLine : public InterfaceQueueLine
{
private:
    std::string Perfix;
    int ExpectedTime;
    int TotalTickets;
    int ServedClients;
    int WaitingClients;
    int NumOfClientForId;

public:
    clsQueueLine(std::string Perfix, int ExpectedTime) // constructor
    {
        this->WaitingClients = 0;
        this->TotalTickets = 0;
        this->ServedClients = 0;

        this->Perfix = Perfix;
        this->ExpectedTime = ExpectedTime;
    };

private:
    class clsTicket
    {

        std::string TimeDate;
        std::string ClientId;

    public:
        clsTicket(int NumOfClient, std::string Perfix)
        {
            TimeDate = clsDate::GetLocalDateAndTime();
            ClientId = Perfix + std::to_string(NumOfClient);
        };

        std::string GetClientId()
        {
            return this->ClientId;
        };

        std::string GetDateTimeDetails()
        {
            return this->TimeDate;
        };
    };

    std::queue<clsTicket> QueueOfLine; // FIFO

public:
    void IssueTicket() override
    {
        TotalTickets++; // as new client issued a ticket
        WaitingClients++;
        NumOfClientForId++;
        clsTicket NewTicket(NumOfClientForId, this->Perfix); // ticket info object includes time and client id

        QueueOfLine.push(NewTicket);
    };

    void PrintInfo() override
    {
        std::cout << "\t\t\t\t\t___________________________\n";
        std::cout << "Perfix: " << this->Perfix << std::endl;
        std::cout << "Total Tickets: " << this->TotalTickets << std::endl;
        std::cout << "Served Clients: " << this->ServedClients << std::endl;
        std::cout << "Waiting Clients: " << this->WaitingClients << std::endl;
        std::cout << "\t\t\t\t\t___________________________\n";
    };

    void PrintTicketsLineRtl() override
    {
        std::queue<clsTicket> TempLine = this->QueueOfLine;
        std::string strLine = "";
        while (!TempLine.empty())
        {
            strLine += TempLine.front().GetClientId() + "<---  "; // get client that that will be served at first  id form queue object
            TempLine.pop();
        };
        strLine.pop_back(); // to remove the last "<---"
        std::cout << strLine << std::endl;
    };

    void PrintTicketsLineLtr() override
    {
        std::queue<clsTicket> TempLine = this->QueueOfLine;
        std::stack<clsTicket> TempStack; // to reverse queue
        std::string strLine = "";

        // Reverse Queue
        while (!TempLine.empty())
        {
            TempStack.push(TempLine.front()); // push the front queue element to stack
            TempLine.pop();
        };

        while (!TempStack.empty()) // as stack follow LIFO
        {
            strLine += TempStack.top().GetClientId() + "--->  "; // get client that that will be served at first  id form queue object
            TempStack.pop();
        };

        strLine.pop_back(); // to remove the last "<---"
        std::cout << strLine << std::endl;
    };

private:
    void PrintSingleTicket(clsTicket Client)
    {
        std::cout << "\t\t\t\t\t\t" << Client.GetClientId() << "\n";
        std::cout << "\t\t\t\t\t" << Client.GetDateTimeDetails() << "\n";
        std::cout << "Waiting Clients= " << this->WaitingClients << "\n";
        std::cout << "Serve Time In: " << WaitingClients * ExpectedTime << std::endl;
    };

public:
    void PrintAllTickets() override
    {
        std::queue<clsTicket> TempLine = this->QueueOfLine;
        std::cout << "\n\t\t\t\t\tTickets\n";
        std::cout << "\t\t\t\t_____________________________\n";

        while (!TempLine.empty())
        {
            PrintSingleTicket(TempLine.front());
            std::cout << "\t\t\t\t_____________________________\n";
            TempLine.pop();
        };
    };

    void ServeNextClient() override
    {
        this->WaitingClients--;
        this->ServedClients++;
        this->QueueOfLine.pop(); 
    };



};
