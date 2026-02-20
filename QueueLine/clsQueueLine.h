#include <queue>
#include<string>
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
     std::string Perfix ;
     int ExpectedTime ;

     public:
     clsQueueLine(std::string Perfix , int ExpectedTime) // constructor 
     {
        this->Perfix = Perfix;
        this->ExpectedTime = ExpectedTime ;
     };



};
