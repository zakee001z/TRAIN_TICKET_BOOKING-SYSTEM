#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y);
void trainmove(int x, int y);
void start();
void prntschedule();
void booktickets(int T_X, int day, int combo);
void cancelbooking(int T_X, int day, int combo);
int combodecider(int boarding, int destination); // to convert the combination of routes into a single integer value to access in array
int daydecider(string departure); // convert day name into a integer to access in array
int traindecider(int TrainNumber); // to -1 from the input that user gives for train since array starts from 0
void prntoptions();
void prntXX(int T_X, int day, int combo); // prnt unavailable seats
int billcalc(int T_X, int day, int combo); // to calculate bill
string boardingcalc(int T_X, int boarding); // to convert the boarding num input into a name
string destinationcalc(int T_X, int destination); // to convert the destination num input into a name
void prnt0();
void prntseat1();
void prntbox1();
void check();

int seats[2][7][6][21] = {0};

int main()
{
	int TrainNumber, boarding, destination, X, OP, somethin ;
	int T_X, day, combo, value;
	string departure, entrystation_name, exitstation_name;
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
    	while (true) {
        int choice;
	system("cls");
        cout << "  _____________________________________   " << endl;
        cout << " |           Ticket Booking            |  " << endl;
        cout << " |_____________________________________|  " << endl;
        cout << " 1. Continue" << endl;
        cout << " 2. Return to Homepage" << endl;
        cout << " Enter your choice: ";
        cin >> choice;
	system("cls");
	if (choice == 2) {
            start();
        }
	if (choice == 1){
	cout << " Select a Train to show further details: " << endl;
        cout << " 1. T1 - Lahore to Rawalpindi " << endl;
        cout << " 2. T2 - Rawalpindi to Lahore " << endl;
        cout << " Enter train number (1 or 2): ";
        cin >> TrainNumber;
        T_X = traindecider(TrainNumber);

        if (T_X == -1) {
            cout << " Invalid train number. Try again." << endl;
            continue;
        }

        if (T_X == 0) // T1
        {
	    cout << endl;
            cout << " Available Stations for T1: " << endl;
            cout << " 1. Lahore           " << endl;
            cout << " 2. Gujrat           " << endl;
            cout << " 3. Jhelum           " << endl;
            cout << " 4. Rawalpindi       " << endl;
        } else // T2
        {
	    cout << endl;
            cout << " Available Stations for T2: " << endl;
            cout << " 1. Rawalpindi       " << endl;
            cout << " 2. Jhelum           " << endl;
            cout << " 3. Gujrat           " << endl;
            cout << " 4. Lahore           " << endl;
        }
	cout<<endl;
        cout << " Enter your desired boarding station number: ";
        cin >> boarding;
        cout << " Enter your destination's station number: ";
        cin >> destination;

        if (boarding >= destination) {
            cout << " Invalid route: Destination must be after boarding station." << endl;
	    system("cls");
            continue;
        }

        combo = combodecider(boarding, destination);

        cout << endl;
        cout << " NOTE: The day of departure follows this week schedule " << endl;
        cout << " Enter your day of departure: ";
        cin >> departure;
        day = daydecider(departure);

        // Validate train-day combination
        if ((T_X == 0 && (day == 0 || day == 2 || day == 4 || day == 6)) ||
            (T_X == 1 && (day == 1 || day == 3 || day == 5))) {
            system("cls");
            cout << " Thank you for providing the details. " << endl;
	    cout << endl;
	    cout << " Validating route " << endl;
            Sleep(2500);

            while (true) {
                prntoptions();
                cout << "   Enter an option: ";
                cin >> OP;
		if (OP == 1){
			system("cls");
			prntbox1();
			prntseat1();
			prntXX(T_X, day, combo);
			check();
			}
                if (OP == 2) {
                    system("cls");
                    booktickets(T_X, day, combo);
                } else if (OP == 3) {
                    system("cls");
                    cancelbooking(T_X, day, combo);
                }
		  else if (OP == 4) {
		  system("cls");
		  value=billcalc(T_X, day, combo);
		  entrystation_name=boardingcalc(T_X, boarding);
		  exitstation_name=destinationcalc(T_X, destination);
		  cout<< "  _____________________________  "<<endl;
		  cout<< " |       Passenger Ticket      | "<<endl;
		  cout<< " |_____________________________| "<<endl;
		  cout<< " Train      : T"<< TrainNumber <<endl;
		  cout<< " From       : "<< entrystation_name <<endl;
		  cout<< " To         : "<< exitstation_name <<endl;
		  cout<< " Day        : "<< departure <<endl;
		  cout<<endl;
		  cout<< " Fare       : Rs. "<< value <<endl;
		  cout<<endl;
		  cout<<endl;
		  cout<< " Press 0 to return to menu: ";
		  cin>> somethin;
		}
		   else if (OP == 5) {
		    system("cls");
                    start();
		    break;
                } else {
			system("cls");
                    cout << " Invalid option. Try again." << endl;
			Sleep(1500);
                }
	     }
            }
        } else {
		system("cls");
            cout << " This train doesn't operate on the entered day." << endl;
		Sleep(1500);
		
        }
    }

    return 0;
}
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X=x;
	coordinates.Y=y;
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

void start()
{
    int x;
    system("cls");
    while(true)
    {
    system("cls");
    cout << "  __________________________________________________   "<< endl;
    cout << " |          NATIONAL RAILWAY BOOKING SYSTEM         |  "<< endl;
    cout << " |__________________________________________________|  "<< endl;
    cout << " | a) Press 1 to see train schedule                 |  "<< endl;
    cout << " | b) Press 2 to proceed to the ticket booking menu |  "<< endl;
    cout << " |__________________________________________________|  "<< endl;
    cout << endl;
    cout << "   Select option number to continue: ";
    cin >> x;
    if (x == 1)
    {
        system("cls");
        prntschedule();
	break;
    }
    if (x == 2)
    {
        system("cls");
	break;
    }
    else
    {
	system("cls");
	cout<< " The option you entered was invalid, Please enter a valid option ";
	Sleep(1500);
    }
    }
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
if(combo==2){
	seats[T_X][day][0][book - 1] = 1;
	seats[T_X][day][1][book - 1] = 1;
	seats[T_X][day][3][book - 1] = 1;
	seats[T_X][day][4][book - 1] = 1;
	seats[T_X][day][5][book - 1] = 1;
	}
if(combo==1){
	seats[T_X][day][0][book - 1] = 1;
	seats[T_X][day][2][book - 1] = 1;
	seats[T_X][day][3][book - 1] = 1;
	seats[T_X][day][4][book - 1] = 1;
	}
if(combo==0){
	seats[T_X][day][1][book - 1] = 1;
	seats[T_X][day][2][book - 1] = 1;
	}
if(combo==3){
	seats[T_X][day][1][book - 1] = 1;
	seats[T_X][day][2][book - 1] = 1;
	seats[T_X][day][4][book - 1] = 1;
	}
if(combo==4){
	seats[T_X][day][1][book - 1] = 1;
	seats[T_X][day][2][book - 1] = 1;
	seats[T_X][day][4][book - 1] = 1;
	}
if(combo==5){
	seats[T_X][day][2][book - 1] = 1;
}
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
if(combo==2){
	seats[T_X][day][0][cancel - 1] = 0;
	seats[T_X][day][1][cancel - 1] = 0;
	seats[T_X][day][3][cancel - 1] = 0;
	seats[T_X][day][4][cancel - 1] = 0;
	seats[T_X][day][5][cancel - 1] = 0;
	}
if(combo==1){
	seats[T_X][day][0][cancel - 1] = 0;
	seats[T_X][day][2][cancel - 1] = 0;
	seats[T_X][day][3][cancel - 1] = 0;
	seats[T_X][day][4][cancel - 1] = 0;
	}
if(combo==0){
	seats[T_X][day][1][cancel - 1] = 0;
	seats[T_X][day][2][cancel - 1] = 0;
	}
if(combo==3){
	seats[T_X][day][1][cancel - 1] = 0;
	seats[T_X][day][2][cancel - 1] = 0;
	seats[T_X][day][4][cancel - 1] = 0;
	}
if(combo==4){
	seats[T_X][day][1][cancel - 1] = 0;
	seats[T_X][day][2][cancel - 1] = 0;
	seats[T_X][day][4][cancel - 1] = 0;
	}
if(combo==5){
	seats[T_X][day][2][cancel - 1] = 0;
}
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
    if (departure == "Monday" || departure == "monday" || departure == "MONDAY") return 0;
    else if (departure == "Tuesday" || departure == "tuesday" || departure == "TUESDAY") return 1;
    else if (departure == "Wednesday" || departure == "wednesday" || departure == "WEDNESDAY") return 2;
    else if (departure == "Thursday" || departure == "thursday" || departure == "THURSDAY") return 3;
    else if (departure == "Friday" || departure == "friday" || departure == "FRIDAY") return 4;
    else if (departure == "Saturday" || departure == "saturday" || departure == "SATURDAY") return 5;
    else if (departure == "Sunday" || departure == "sunday" || departure == "SUNDAY") return 6;
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

void prntbox1() 
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

void prnt0() // for asthetics
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

void prntseat1() // simple printing for seats regardless of availability
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

}

void prntXX(int T_X, int day, int combo) // used to display which seats are unavailable utilizing a for loop to check seat status 0-20
{
	int x=14, y=9;
	for(int i=0; i<10; i++)
	{
	gotoxy(x, y);
		if(seats[T_X][day][combo][i]==1)
		{
			cout<< "XX";

		}
		x=x+9;
		if(x==32) 
		{
			x=14;
			y=y+4;
		}		
	}
	
	x=42, y=9;
	for(int i=10; i<21; i++)
	{
	gotoxy(x, y);
		if(seats[T_X][day][combo][i]==1)
		{
			cout<< "XX";
		}
		x=x+9;
		if(x==60) 
		{
			x=42;
			y=y+4;
		}		
	}
	gotoxy(0, y+2);
}

void check() // used in check available seats to return to option menu
{   
	int check;
	int OP; 
	cout<< "  "<<endl;
	cout<< "    a)Enter 0 to return to menu"<<endl;

	cout<<endl;
	cout<< "    Enter option: ";
	cin>> check;
		if(check==0) 
		{
			system("cls");
		}
		if(check==1) 
		{
			system("cls");
		}
}

int billcalc(int T_X, int day, int combo) // bill calculator used in display reservations
{
	int No_Of_Tickets=0;
	for(int i=0; i<20; i++)
	{
		if(seats[T_X][day][combo][i]==1)
		{
			No_Of_Tickets++;
		}
	}

	int bill=No_Of_Tickets*500;

	return bill;
}
string boardingcalc(int T_X, int boarding) // for display reservations to see boarding station name
{
	string entry;
	if(T_X==0 && boarding==1)
	{
		entry="Lahore";
	}
	if(T_X==0 && boarding==2)
	{
		entry="Gujrat";
	}
	if(T_X==0 && boarding==3)
	{
		entry="Jhelum";
	}
	if(T_X==0 && boarding==4)
	{
		entry="Rawalpindi";
	}
	if(T_X==1 && boarding==1)
	{
		entry="Rawalpindi";
	}
	if(T_X==1 && boarding==2)
	{
		entry="Jhelum";
	}
	if(T_X==1 && boarding==3)
	{
		entry="Gujrat";
	}
	if(T_X==1 && boarding==4)
	{
		entry="Lahore";
	}

	return entry;
}

string destinationcalc(int T_X, int destination) // for display reservations to see the name of the destination
{
	string exit;
	if(T_X==0 && destination==1)
	{
		exit="Lahore";
	}
	if(T_X==0 && destination==2)
	{
		exit="Gujrat";
	}
	if(T_X==0 && destination==3)
	{
		exit="Jhelum";
	}
	if(T_X==0 && destination==4)
	{
		exit="Rawalpindi";
	}
	if(T_X==1 && destination==1)
	{
		exit="Rawalpindi";
	}
	if(T_X==1 && destination==2)
	{
		exit="Jhelum";
	}
	if(T_X==1 && destination==3)
	{
		exit="Gujrat";
	}
	if(T_X==1 && destination==4)
	{
		exit="Lahore";
	}

	return exit;
}