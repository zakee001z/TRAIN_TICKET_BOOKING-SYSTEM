#include<iostream>
#include<windows.h>
using namespace std;

int combodecider(int boarding, int destination);
void cancelbooking(int T_X, int day, int combo);
void booktickets(int T_X, int day, int combo);
int daydecider(string departure);
int traindecider(int TrainNumber);
void prntoptions();

int seats[2][7][6][20] = {0}; // 2 trains, 7 days, 6 routes, 20 seats



int main()
{
    int TrainNumber, boarding, destination, X, OP;
    int T_X, day, combo;
    string departure;
        
        
    while(true)
    {  
        cout << "  _____________________________________   "<< endl;
        cout << " |           Ticket Booking            |  "<< endl;
        cout << " |_____________________________________|  "<< endl;
        cout << endl;
        cout << " Select a Train to show further details: "<< endl;
        cout << " 1. T1 - Lahore to Rawalpindi "<< endl;
        cout << " 2. T2 - Rawalpindi to Lahore "<< endl;
        cout << " Enter train number (1 or 2): ";
        cin >> TrainNumber;  
        cout << endl;
        T_X= traindecider(TrainNumber);

        if (T_X == 1)
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
            combo= combodecider(boarding, destination);
                if (boarding < destination)
                {
                cout << endl;
                cout << " NOTE: The day of departure follows this week schedule "<< endl;
                cout << " Enter your day of departure: ";
                cin >> departure;  // Global variable departure
                day= daydecider(departure);
                    if (day == 0 || day == 2 || day == 4|| day == 6)
                    {
                        system("cls");
                        cout << " Thank you for providing the details. "<< endl;
                        Sleep(500);
                        while(true)
                        {
                            prntoptions();
            			    cout<< "  "<<endl;
			                cout<< "   Enter an option: ";
			                cin>> OP;
                            if(OP==2)
                            {
                                system("cls");
                                booktickets(T_X, day, combo);
                            }
                            if(OP==3)
                            {
                                system("cls");
                                cancelbooking(T_X, day, combo);
                            }
                            if(OP==5)
                            {
                                break;
                            }
                        }
                    }
                }
                

        }
        else if (T_X == 2)
        {
            cout << " Available Stations for T2: "<< endl;
            cout << " 1. Rawalpindi       "<< endl;
            cout << " 2. Jhelum           "<< endl;
            cout << " 3. Gujrat           "<< endl;
            cout << " 4. Lahore           "<< endl;
            cout << endl;
            cout << " Enter your desired boarding station number: ";
            cin >> boarding; 
            cout << " Enter your destination's station number: ";
            cin >> destination;  

            if (boarding < destination)
            {
                cout << endl;
                cout << " NOTE: The day of departure follows this week schedule "<< endl;
                cout << " Enter your day of departure: ";
                cin >> departure;  
                day= daydecider(departure);
                if (day == 1 || day == 3 || day == 5)
                {
                    system("cls");
                    cout << " Thank you for providing the details. "<< endl;
                    Sleep(500);
                    while(true)
                    {    
                    prntoptions();
           			cout<< "  "<<endl;
			        cout<< "   Enter an option: ";
			        cin>> OP;
                        if(OP==2)
                        {
                            system("cls");
                            booktickets(T_X, day, combo);
                        }
                        if(OP==3)
                        {
                            system("cls");
                            cancelbooking(T_X, day, combo);
                        }
                        if(OP==5)
                        {
                            break;
                        }
                    }
                }
            }

        }
    }
}
    void booktickets(int T_X, int day, int combo)
    {
        int book;
        while(true)
        {
        cout<<"Enter a seat number (1-20) or 0 to return: ";
        cin>>book;
            if(book==0)
            {
            break;
            }
            if(book<0 || book>20)
            {
            cout<< "Invalid seat number. Please enter a number between 1 and 20."<<endl;
            }
            else if(seats[T_X][day][combo][book-1]==1)
            {
            cout<<"This seat is already booked. Please choose a different one."<<endl;
            }
            else
            {
            seats[T_X][day][combo][book-1]=1;
            cout<<"Seat booked successfully!"<<endl;
            }
        }
        system("cls");
    }

    void cancelbooking(int T_X, int day, int combo)
    {
        int cancel;
        while(true)
        {
            cout<<"Enter the seat number to cancel (1-20) or 0 to return: ";
            cin>>cancel;
            if(cancel==0)
            {
                break;
            }
            if(cancel<0 || cancel>20)
            {
                cout<<"ENTER A VALID SEAT NUMBER...."<<endl;
            }
            else if(seats[T_X][day][combo][cancel-1]==0)
            {
                cout<<"This seat is not currently booked."<<endl;
            }
            else
            {
                seats[T_X][day][combo][cancel-1]=0;
                cout<<"Booking cancelled successfully."<<endl;
            }
        }
        system("cls");
    }

    int combodecider(int boarding, int destination)
    {


        int type;
        if (boarding == 1 && destination == 2)
        {
            type=0;
        }
        if (boarding == 1 && destination == 3)
        {
            type=1;
        }
            if (boarding == 1 && destination == 4)
        {
            type=2;
        }
        if (boarding == 2 && destination == 3)
        {
            type=3;
        }
        if (boarding == 2 && destination == 4)
        {
            type=4;
        }
        if (boarding == 3 && destination == 4)
        {
            type=5;
        }
        return type;
    }

    int daydecider(string departure)
    {
        if(departure == "Monday")
        {
            return 0;
        }
        else if(departure == "Tuesday")
        {
            return 1;
        }
        else if(departure == "Wednesday")
        {
            return 2;
        }
        else if(departure == "Thursday")
        {
            return 3;
        }
        else if(departure == "Friday")
        {
            return 4;
        }
        else if(departure == "Saturday")
        {
            return 5;
        }
        else
        {
            return 6;
        }
    }

    int traindecider(int TrainNumber)
    {
        if(TrainNumber == 1)
        {
            return 0;
        }
        else if(TrainNumber == 2)
        {
            return 1;
        }
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