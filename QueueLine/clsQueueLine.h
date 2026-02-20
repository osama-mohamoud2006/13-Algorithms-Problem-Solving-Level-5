#pragma once
#include <queue>
#include <stack>
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
        this->NumOfClientForId = 0;

        this->Perfix = Perfix;
        this->ExpectedTime = ExpectedTime;
    };

private:
    class clsTicket
    {

        std::string TimeDate;
        std::string ClientId;
        int NumOfClient;

    private:
        std::string GetLocalDateAndTime()
        {
            time_t epoch_time = time(0);
            tm *date_now = localtime(&epoch_time);
            std::string time = std::to_string(date_now->tm_hour) + ":" + std::to_string(date_now->tm_min) + ":" + std::to_string(date_now->tm_sec);
            //  d/m/y + time
            return (std::to_string(date_now->tm_mday) + "/" + std::to_string((date_now->tm_mon) + 1) + "/" + std::to_string((date_now->tm_year) + 1900) + " - " + time);
        }

    public:
        clsTicket(int NumOfClient, std::string Perfix)
        {
            TimeDate = GetLocalDateAndTime();
            this->NumOfClient = NumOfClient;
            ClientId = Perfix + std::to_string(NumOfClient);
        };

        std::string GetClientId() const
        {
            return this->ClientId;
        };

        std::string GetDateTimeDetails() const
        {
            return this->TimeDate;
        };

        int GetClientNum() const
        {
            return NumOfClient;
        }
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
        std::string Arrow = "--->  ";
        while (!TempLine.empty())
        {
            strLine += TempLine.front().GetClientId() + Arrow; // get client that that will be served at first  id form queue object
            TempLine.pop();
        };

        if (strLine != "")
        {
            strLine = strLine.substr(0, strLine.length() - Arrow.length()); // to remove the last "<---"
        };
        std::cout << strLine << std::endl;
    };

    void PrintTicketsLineLtr() override
    {
        std::queue<clsTicket> TempLine = this->QueueOfLine;
        std::stack<clsTicket> TempStack; // to reverse queue
        std::string strLine = "";
        std::string Arrow = "<---  ";

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

        if (strLine != "") // to remove the last "<---"
        {
            strLine = strLine.substr(0, strLine.length() - Arrow.length()); // to remove the last "<---"
        };

        std::cout << strLine << std::endl;
    };

private:
    void PrintSingleTicket(clsTicket Client)
    {
        std::cout << "\t\t\t\t\t\t" << Client.GetClientId() << "\n";
        std::cout << "\t\t\t\t\t" << Client.GetDateTimeDetails() << "\n";

        static int WClient = 0;
        std::cout << "\t\t\t\t\t" << "Waiting Clients= " << WClient++ << "\n";
        std::cout << "\t\t\t\t\t" << "Serve Time In: " << WClient * ExpectedTime << std::endl;
    };

public:
    void PrintAllTickets() override
    {
        std::queue<clsTicket> TempLine = this->QueueOfLine;
        std::cout << "\n\t\t\t\t\t        Tickets\n";
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
        if (!QueueOfLine.empty())
        {
            this->WaitingClients--;
            this->ServedClients++;
            this->QueueOfLine.pop();
        };
    };
};
