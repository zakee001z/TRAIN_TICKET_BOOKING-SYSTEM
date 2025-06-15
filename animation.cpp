#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y);
void trainmove(int x, int y);

int main()
{
	system("cls");
	int x=2, y=18;	
	while(true)
	{

		trainmove(x, y);
		x=x+1;
		if(x==120)
		{
			break;
		}
	}
}

void trainmove(int x, int y)
{
gotoxy(x, y);
cout<< "       ________________________ "<<endl;
gotoxy(x, y+1);
cout<< "  ___||__|  |_|__|  |_|__|___||___ "<<endl;
gotoxy(x, y+2);
cout<< " |                                > "<<endl;
gotoxy(x, y+3);
cout<< " '--(o)--------------(o)-------(o)--' "<<endl;
gotoxy(x, y+4);
cout<< " ================================="<<endl; 
Sleep(35);
}
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X=x;
	coordinates.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
