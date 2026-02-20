#include <iostream>
#include "E:\projects\c++ course\13 - Algorithms  Problem Solving Level 5\QueueLine\clsQueueLine.h"
using namespace std;

int main()
{

    clsQueueLine ServiceQueue = clsQueueLine("A0", 10);

    ServiceQueue.IssueTicket();
    ServiceQueue.IssueTicket();
    ServiceQueue.IssueTicket();
    ServiceQueue.IssueTicket();

    cout << "\n\t\t\t\t\tService Queue Info\n";
    ServiceQueue.PrintInfo();

    ServiceQueue.PrintTicketsLineRtl();
    ServiceQueue.PrintTicketsLineLtr();

    cout << "\n\n";
    ServiceQueue.PrintAllTickets();
};