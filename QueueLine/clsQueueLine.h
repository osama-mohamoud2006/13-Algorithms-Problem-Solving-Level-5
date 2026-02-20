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
    // FIFO
    std::string Perfix;
    int ExpectedTime;
    int TotalTickets;
    int ServedClients;
    int WaitingClients;
    int NumOfClient ;

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
        int NumOfClient ; 

    public:
        clsTicket(int NumOfClient)
        {
            TimeDate = clsDate::GetLocalDateAndTime();
            this->NumOfClient = NumOfClient;
        };
    };


    std::queue<clsTicket> Line;

public:
    void IssueTicket() override
    {
        TotalTickets++;
        WaitingClients++;
        NumOfClient++;
        clsTicket NewTicket(NumOfClient);
        Line.push(NewTicket);
    };
};
