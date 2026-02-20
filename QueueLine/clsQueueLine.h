#pragma once
#include <queue>
#include <stack>
#include <string>
class InterfaceQueueLine
{
public:
    virtual void IssueTicket() = 0;
    virtual bool ServeNextClient() = 0;
    virtual void PrintTicketsLineRtl() = 0;
    virtual void PrintTicketsLineLtr() = 0;
    virtual void PrintInfo() = 0;
    virtual void PrintAllTickets() = 0;
};

class clsQueueLine : public InterfaceQueueLine
{
private:
    std::string _Perfix;
    int _ExpectedTimeForServingEachClient;
    int _TotalTickets;

public:
    clsQueueLine(std::string Perfix, int ExpectedTime) // constructor
    {
        this->_Perfix = Perfix;
        this->_TotalTickets = 0;

        this->_ExpectedTimeForServingEachClient = ExpectedTime;
    };

private:
    class clsTicket
    {
        short _Number = 0;
        std::string _Prefix;
        std::string _TicketTime;
        short _WaitingClients = 0;
        short _AverageServeTime = 0;

        /// short _ExpectedServeTime = 0;

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
        clsTicket(std::string Prefix, int Num, int WaitingClient, short AverageServeTime)
        {
            this->_Prefix = Prefix;
            this->_Number = Num;
            this->_WaitingClients = WaitingClient;
            this->_AverageServeTime = AverageServeTime;
            _TicketTime = GetLocalDateAndTime();
        };

        std::string GetClientId()
        {
            return this->_Prefix + std::to_string(_Number);
        };

        std::string GetDateTimeDetails() const
        {
            return this->_TicketTime;
        };

        void SetNewWaitingClient(int Num)
        {
            _WaitingClients = Num;
        }

        int GetClientNum() const
        {
            return _Number;
        }

        int ExpectedServeTime()
        {
            return this->_AverageServeTime * this->_WaitingClients;
        };

        void PrintSingleTicket()
        {
            std::cout << "\t\t\t\t\t\t" << GetClientId() << "\n";
            std::cout << "\t\t\t\t\t" << GetDateTimeDetails() << "\n";
            std::cout << "\t\t\t\t\t" << "Waiting Clients= " << _WaitingClients << "\n";
            std::cout << "\t\t\t\t\t" << "Serve Time In: " << ExpectedServeTime() << std::endl;
        };
    };

    std::queue<clsTicket> QueueOfLine; // FIFO

public:
    int QueueLineSize()
    {
        return QueueOfLine.size();
    }

    void IssueTicket() override
    {
        _TotalTickets++; // as new client issued a ticket

        clsTicket Ticket(this->_Perfix, _TotalTickets, WaitingClients(), _ExpectedTimeForServingEachClient); // ticket info object includes time and client id

        QueueOfLine.push(Ticket);
    };

    int WaitingClients()
    {
        return QueueOfLine.size();
    }

    int ServedClients()
    {
        return this->_TotalTickets - WaitingClients();
    }

    void PrintInfo() override
    {
        std::cout << "\t\t\t\t\t___________________________\n";
        std::cout << "Perfix: " << this->_Perfix << std::endl;
        std::cout << "Total Tickets: " << this->_TotalTickets << std::endl;
        std::cout << "Served Clients: " << this->ServedClients() << std::endl;
        std::cout << "Waiting Clients: " << this->WaitingClients() << std::endl;
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

    void PrintAllTickets() override
    {
        std::queue<clsTicket> TempLine = this->QueueOfLine;
        std::cout << "\n\t\t\t\t\t      Tickets\n";
        std::cout << "\t\t\t\t_____________________________\n";

        while (!TempLine.empty())
        {
            TempLine.front().PrintSingleTicket();
            std::cout << "\t\t\t\t_____________________________\n";
            TempLine.pop();
        };
    };

    bool ServeNextClient() override
    {
        if (QueueOfLine.empty())
        {
            return false;
        }
        else
        {
            QueueOfLine.pop();

            return true;
        };
    };

    string WhoIsNext()
    {
        if (!this->QueueOfLine.empty())
        {
            return QueueOfLine.front().GetClientId();
        }
        else
            return "";
    };


};
