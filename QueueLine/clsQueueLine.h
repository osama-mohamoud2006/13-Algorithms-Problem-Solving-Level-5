#include <queue>
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
    int NumOfClient;

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
        clsTicket(int NumOfClient , std::string Perfix)
        {
            TimeDate = clsDate::GetLocalDateAndTime();
            ClientId= Perfix+std::to_string(NumOfClient);
        };
    };

    std::queue<clsTicket> Line; // FIFO

public:
    void IssueTicket() override
    {
        TotalTickets++; // as new client issued a ticket
        WaitingClients++;
        NumOfClient++;
        clsTicket NewTicket(NumOfClient,this->Perfix); // ticket info object includes time and client id

        Line.push(NewTicket);
    };
};
