#include<iostream>
#include<windows.h>
using namespace std;

int TrainNumber, boarding, destination, X;
string departure;

void gotoxy(int x, int y);
void trainmove(int x, int y);
void prntschedule();
void ticketbookingdisplay();
void start();
void prnt0();
void prntbox1();
void prntseat1();
void prntoptions();
void OPTION(int OP);
void cancelbooking(int T_X, int day, int combo);
void booktickets(int T_X, int day, int combo);
int daydecider(string departure);
int traindecider(int TrainNumber);
int combodecider(int boarding, int destination);
void check();

int seats[2][7][6][20] = {0}; // 2 trains, 7 days, 6 routes, 20 seats

int main()
{
	int OP;
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
	prntoptions();
	cout<< "  "<<endl;
	cout<< " Enter an option: ";
	cin>> OP;
	OPTION(OP);
}

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X=x;
	coordinates.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void prntbox1() // should later implement gotoxy function upon each line to print this in middle
{
	int z=1;
	cout<< "       _____________________________________________________    " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |                   PUNJAB EXPRESS                    |   " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |_____________________________________________________|   " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	while(z<4)
	{
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	z=z+1;
	}
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |_____________________________________________________|   " <<endl;
}

void prntbox2()
{
	int z=1;

	cout<< "       _____________________________________________________    " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	while(z<4)
	{
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	z=z+1;
	}
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |   |        |        |         |        |        |   |   " <<endl;
	cout<< "      |    ________ ________           ________ ________    |   " <<endl;
	cout<< "      |                                                     |   " <<endl;
	cout<< "      |_____________________________________________________|   " <<endl;
}

void prnt0()
{
	int n1=1;
	int x=14, y=9;
	while(n1<10)
	{
	gotoxy(x, y);
	cout<< "0";
	n1=n1+1;
	x=x+9;
		if(x==32) 
		{
			x=14;
			y=y+4;
		}
	}
}
void prntseat1()  // for printing seats should later be linked to replace unavailable seat numbers with a #
{
	prnt0();
	int n1=1;
	int x=15, y=9; // for the left side seats

	while(n1<11)
	{
	gotoxy(x, y);
	cout<< n1;
	n1=n1+1;
	x=x+9;
	if(x==33) //value of x should be 22 greater then initial x value
		{
			x=15;
			y=y+4;
		}
	if(n1==10)
		{
			x=23;
		}
	}

	x=42, y=9;  // for the seats at the right side

	while(n1<21)
	{
	gotoxy(x, y);
	cout<< n1;
	n1=n1+1;
	x=x+9;
	if(x==60)
		{
		x=42;
		y=y+4;
		}
	}

	gotoxy(0, y+2); // to get the prompt out of the display temporary fix till we make full display
}



void prntoptions()
{
    system("cls");
    cout << "  ---------------------------------------------  "<<endl;
    cout << " |         TRAIN TICKET BOOKING SYSTEM         | "<<endl;
    cout << "  ---------------------------------------------| "<<endl;
    cout << " | 1. Check Available Seats                    | "<<endl;
    cout << " | 2. Book Tickets                             | "<<endl;
    cout << " | 3. Cancel Booking                           | "<<endl;
    cout << " | 4. Display Reservations                     | "<<endl;
    cout << " | 5. Exit                                     | "<<endl;
    cout << "  ---------------------------------------------  "<<endl;

}

void OPTION(int OP)// checks options and calls their functions and fully applys option1
{
	if(OP==1)   // CHECK AVAILABLE SEATS
	{
	
	system("cls");
	prntbox1();
	prntseat1();
	check();
	
	}
	if(OP==2)
	{   
		system("cls");
	    booktickets ();
	    check();
	    
			
	}
	if(OP==3)
	{
		system("cls");
		cancelbooking();
		check();
	
	}
	if(OP==5)
	{
		system("cls");
		start();
	}
}

void booktickets(int T_X, int day, int combo) {
    int book;
    while (true) {
        cout << "Enter a seat number (1-20) or 0 to return: ";
        cin >> book;

        if (book == 0)
            break;

        if (book < 1 || book > 20)
            cout << "Invalid seat number. Please enter a number between 1 and 20." << endl;
        else if (seats[T_X][day][combo][book - 1] == 1)
            cout << "This seat is already booked. Please choose a different one." << endl;
        else {
            seats[T_X][day][combo][book - 1] = 1;
            cout << "Seat booked successfully!" << endl;
        }
    }
    system("cls");
}

void cancelbooking(int T_X, int day, int combo) {
    int cancel;
    while (true) {
        cout << "Enter the seat number to cancel (1-20) or 0 to return: ";
        cin >> cancel;

        if (cancel == 0)
            break;

        if (cancel < 1 || cancel > 20)
            cout << "ENTER A VALID SEAT NUMBER...." << endl;
        else if (seats[T_X][day][combo][cancel - 1] == 0)
            cout << "This seat is not currently booked." << endl;
        else {
            seats[T_X][day][combo][cancel - 1] = 0;
            cout << "Booking cancelled successfully." << endl;
        }
    }
    system("cls");
}

int combodecider(int boarding, int destination) {
    int type = -1;
    if (boarding == 1 && destination == 2) type = 0;
    else if (boarding == 1 && destination == 3) type = 1;
    else if (boarding == 1 && destination == 4) type = 2;
    else if (boarding == 2 && destination == 3) type = 3;
    else if (boarding == 2 && destination == 4) type = 4;
    else if (boarding == 3 && destination == 4) type = 5;

    return type;
}

int daydecider(string departure) {
    if (departure == "Monday") return 0;
    else if (departure == "Tuesday") return 1;
    else if (departure == "Wednesday") return 2;
    else if (departure == "Thursday") return 3;
    else if (departure == "Friday") return 4;
    else if (departure == "Saturday") return 5;
    else if (departure == "Sunday") return 6;
    else return -1; // invalid input
}

int traindecider(int TrainNumber) {
    if (TrainNumber == 1)
        return 0;
    else if (TrainNumber == 2)
        return 1;
    else
        return -1;
}

void prntoptions() {
    system("cls");
    cout << "  ---------------------------------------------  " << endl;
    cout << " |         TRAIN TICKET BOOKING SYSTEM         | " << endl;
    cout << "  ---------------------------------------------| " << endl;
    cout << " | 1. Check Available Seats                    | " << endl;
    cout << " | 2. Book Tickets                             | " << endl;
    cout << " | 3. Cancel Booking                           | " << endl;
    cout << " | 4. Display Reservations                     | " << endl;
    cout << " | 5. Exit                                     | " << endl;
    cout << "  ---------------------------------------------  " << endl;
}
void check()
{   int check;
    int OP; 
	cout<< "  "<<endl;
	cout<< "    a)Enter 1 to show more seats in next cabin"<<endl;
	cout<< "    b)Enter 0 to return to menu"<<endl;

	cout<<endl;
	cout<< "    Enter option: ";
	cin>> check;
		if(check==0) // here i write the same code as in the main so that the code will keep looping asking for options even after doing everthing
		{
			system("cls");
			prntoptions();
			cout<< "  "<<endl;
			cout<< "   Enter an option: ";
			cin>> OP;
			OPTION(OP);
		}
		if(check==1) 
		{
		
		}
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
    if (x!=0 && x!=1)
    {
	while(true)
	{
	cout<< " The option you entered is invalid kindly enter a valid option to proceed: ";
	cin >> x;
		if(x==1)
		{
			system("cls");
			ticketbookingdisplay();
			break;
		}
		if(x==0)
		{
			system("cls");
			start();
			break;
		}
			
	}
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
                system("cls");// Add booking logic here
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