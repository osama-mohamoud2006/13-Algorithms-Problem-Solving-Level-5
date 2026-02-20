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
    int TotalTickets ; 
    int ServedClients ;
    int WaitingClients;

public:
    clsQueueLine(std::string Perfix, int ExpectedTime) // constructor
    {
        this->Perfix = Perfix;
        this->ExpectedTime = ExpectedTime;
    };

    class clsTicket
    {
    private:
        std::string TimeDate;
        
        clsTicket()
        {

        }

    };
};
