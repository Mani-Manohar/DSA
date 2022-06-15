#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

int main()
{
    char ch;
	system("COLOR 0F");
	// while(1)
	// {
		system("cls");
		cout<<endl<<endl;
		fstream f2;
		f2.open("sysmbol.txt",ios::in);
		while(f2) 
		{
			f2.get(ch);
			cout<<ch;
		}
	Sleep(10);
	system("COLOR 0");
		char a[]="                \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb STUDENT TRANSPORT MGMT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
		int size;
		size=strlen(a);
		for(int i=0;i<size;i++)
		{
			Sleep(25);
			cout<<a[i];
		}
		int c=1;
		cout<<endl<<endl;
		Sleep(0);
		cout<<"\n                    \t\t1.REGISTER NOW \n                    \t\t2.STAFF LOGIN \n                    \t\t3.STUDENT LOGIN \n"
		<<"                    \t\t4.NOTICES";
	for(int i=0;i<1;i++)
    {
    	int x = 16;
    	int y = 10;
    	for (y=4;y<13;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "\xdb";
    	  Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}
  		y=13;
  		for (x=16;x<63;x++)  
   		{
    	  gotoXY(x,y);
    	  cout << "\xdb";
    	  Sleep(20);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}
  		for (y=4;y<14;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "\xdb";
    	  Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}
    }
	for(int i=0;i<1;i++)
    {
    	int x = 1;
    	int y = 15;
    	for (x=40;x>1;x--)  
   		{
    	  gotoXY(x,y);
    	  cout << "Made by Manohar";
    	  Sleep(100);
    	  gotoXY(x,y); 
		  cout << "                                                         ";
		     cout<<"                                            "; 
  		}
  		cout <<endl<<"       Made by Manohar"<<endl;
	}
//    register_now r1;
//    staff_login s1;
//    student_login s2;
    return 0;
}