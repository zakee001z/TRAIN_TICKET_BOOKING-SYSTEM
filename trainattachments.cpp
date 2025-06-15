#include<iostream>
#include<windows.h>
using namespace std;

// Global Variables
int TrainNumber, boarding, destination, X;
string departure;

// Function declarations
void gotoxy(int x, int y);
void trainmove(int x, int y);
void prntschedule();
void ticketbookingdisplay();
void start();

int main()
{
    system("cls");
    int x=2, y=18;
    while(true)
    {
        trainmove(x, y);
        x = x + 1;
        if(x == 120)
        {
            break;
        }
    }
    start();
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void trainmove(int x, int y)
{
    gotoxy(x, y);
    cout << "       ________________________ "<< endl;
    gotoxy(x, y + 1);
    cout << "  ___||__|  |_|__|  |_|__|___||___ "<< endl;
    gotoxy(x, y + 2);
    cout << " |                                > "<< endl;
    gotoxy(x, y + 3);
    cout << " '--(o)--------------(o)-------(o)--' "<< endl;
    gotoxy(x, y + 4);
    cout << " ================================="<< endl;
    Sleep(20);
}

void prntschedule()
{
    int x;
    cout << " _____________________________________________________________________________  "<< endl;
    cout << "|                 NATIONAL RAILWAY BOOKING SYSTEM - TRAIN SCHEDULE            | "<< endl;
    cout << "|   Train: T1  |  Route: Lahore - Rawalpindi  |  Runs on: Mon, Wed, Fri, Sun  | "<< endl;
    cout << "|_____________________________________________________________________________| "<< endl;
    cout << "  | Station      | Arrival   | Departure | Distance (km) |     Status       |   "<< endl;
    cout << "  |--------------|-----------|-----------|---------------|------------------|   "<< endl;
    cout << "  | Lahore       |    ---    | 08:00 AM  |      0        |  Boarding        |   "<< endl;
    cout << "  | Gujrat       | 09:30 AM  | 09:40 AM  |    120        |  Stop            |   "<< endl;
    cout << "  | Jhelum       | 10:30 AM  | 10:40 AM  |    180        |  Stop            |   "<< endl;
    cout << "  | Rawalpindi   | 11:30 AM  |    ---    |    290        |  Final Stop      |   "<< endl;
    cout << "  |______________|___________|___________|_______________|__________________|   "<< endl;
    cout << endl;
    cout << "     Train: T2  |  Route: Rawalpindi - Lahore  |  Runs on: Tue, Thu, Sat      "<< endl;
    cout << "   _________________________________________________________________________  "<< endl;
    cout << "  | Station      | Arrival   | Departure | Distance (km) |     Status       | "<< endl;
    cout << "  |--------------|-----------|-----------|---------------|------------------| "<< endl;
    cout << "  | Rawalpindi   |    ---    | 03:00 PM  |      0        |  Boarding        | "<< endl;
    cout << "  | Jhelum       | 03:50 PM  | 04:00 PM  |    110        |  Stop            | "<< endl;
    cout << "  | Gujrat       | 04:50 PM  | 05:00 PM  |    170        |  Stop            | "<< endl;
    cout << "  | Lahore       | 06:30 PM  |    ---    |    290        |  Final Stop      | "<< endl;
    cout << "  |______________|___________|___________|_______________|__________________| "<< endl;
    cout << endl;
    cout << " Press 1 to head to the ticket booking menu or 0 to return to exit: ";
    cin >> x;
    if (x == 1)
    {
        system("cls");
        ticketbookingdisplay();
    }
    if (x == 0)
    {
        system("cls");
        start();
    }
}

void ticketbookingdisplay()
{
    cout << "  _____________________________________   "<< endl;
    cout << " |           Ticket Booking            |  "<< endl;
    cout << " |_____________________________________|  "<< endl;
    cout << endl;
    cout << " Select a Train to show further details: "<< endl;
    cout << " 1. T1 - Lahore to Rawalpindi "<< endl;
    cout << " 2. T2 - Rawalpindi to Lahore "<< endl;
    cout << " Enter train number (1 or 2): ";
    cin >> TrainNumber;  // Global variable TrainNumber
    cout << endl;

    if (TrainNumber == 1)
    {
        cout << " Available Stations for T1: "<< endl;
        cout << " 1. Lahore           "<< endl;
        cout << " 2. Gujrat           "<< endl;
        cout << " 3. Jhelum           "<< endl;
        cout << " 4. Rawalpindi       "<< endl;
        cout << endl;
        cout << " Enter your desired boarding station number: ";
        cin >> boarding;  // Global variable boarding
        cout << " Enter your destination's station number: ";
        cin >> destination;  // Global variable destination

        if (boarding < destination)
        {
            cout << endl;
            cout << " NOTE: The day of departure follows this week schedule "<< endl;
            cout << " Enter your day of departure: ";
            cin >> departure;  // Global variable departure
            if (departure == "Monday" || departure == "Wednesday" || departure == "Friday" || departure == "Sunday")
            {
                // Add booking logic here
            }
        }
        else
        {
            cout << " Unfortunately the destination you entered is not in the travel schedule kindly visit the schedule page to see any available trains for your destination "<< endl;
            cout << endl;
            cout << " Press 1 to open the schedule page or 0 to exit ";
            cin >> X;
            if (X == 1)
            {
                system("cls");
                prntschedule();
            }
            if (X == 0)
            {
                start();
            }
        }
    }

    if (TrainNumber == 2)
    {
        cout << " Available Stations for T2: "<< endl;
        cout << " 1. Rawalpindi       "<< endl;
        cout << " 2. Jhelum           "<< endl;
        cout << " 3. Gujrat           "<< endl;
        cout << " 4. Lahore           "<< endl;
        cout << endl;
        cout << " Enter your desired boarding station number: ";
        cin >> boarding;  // Global variable boarding
        cout << " Enter your destination's station number: ";
        cin >> destination;  // Global variable destination

        if (boarding < destination)
        {
            cout << endl;
            cout << " Note the day of departure follows this week schedule "<< endl;
            cout << " Enter your day of departure: ";
            cin >> departure;  // Global variable departure
            if (departure == "Tuesday" || departure == "Thursday" || departure == "Saturday")
            {
                // Add booking logic here
            }
        }
        else
        {
            cout << endl;
            cout << " Unfortunately the destination you entered is not in the travel schedule kindly visit the schedule page to see any available trains for your destination "<< endl;
            cout << endl;
            cout << " Press 1 to open the schedule page or 0 to exit to menu: ";
            cin >> X;
            if (X == 1)
            {
                system("cls");
                prntschedule();
            }
            if (X == 0)
            {
                start();
            }
        }
    }
}

void start()
{
    int x;
    system("cls");
    cout << "  __________________________________________________   "<< endl;
    cout << " |          NATIONAL RAILWAY BOOKING SYSTEM         |  "<< endl;
    cout << " |__________________________________________________|  "<< endl;
    cout << " | a) Press 1 to see entire train schedule          |  "<< endl;
    cout << " | b) Press 2 to proceed to the ticket booking menu |  "<< endl;
    cout << " |__________________________________________________|  "<< endl;
    cout << endl;
    cout << "   Select option number to continue: ";
    cin >> x;
    if (x == 1)
    {
        system("cls");
        prntschedule();
    }
    if (x == 2)
    {
        system("cls");
        ticketbookingdisplay();
    }
}

