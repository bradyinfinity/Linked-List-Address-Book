#include <iostream>
#include "Contacts.h"
#include <conio.h>
#include <string>
#include <ctime>
#include <chrono>
#pragma warning(disable : 4996)
using namespace std;

//variables for generating current local time
time_t now = time(0);
tm* ltm = localtime(&now);
int tday = ltm->tm_mday;
int tmonth = 1 + ltm->tm_mon;
int tyear = 1900 + ltm->tm_year;

int choice;
bool decide;
Contacts book1;

void consoleInput(){
	if (_kbhit()) {
		switch (_getch()) {
		case '1':
			choice = 1;
			decide = true;
			break;
		case '2':
			choice = 2;
			decide = true;
			break;
		case '3':
			choice = 3;
			decide = true;
			break;
		case '4':
			choice = 4;
			decide = true;
			break;
		case '5':
			choice = 5;
			decide = true;
			break;
		case '6':
			choice = 6;
			decide = true;
			break;
		case '7':
			choice = 7;
			decide = true;
			break;
		default:
			break;
		}
	}
}

void prompt() {
	
	decide = false;
	choice = 0;

	cout << "                                                  Today's Date: " << tmonth << " - " << tday << " - " << tyear << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "     Welcome to the address book application home screen!" << endl <<
		    "     Please enter the number of the action you would like to perform?" << endl
		 << "-----------------------------------------------------------------------------" << endl << endl;

	cout << "     [1] Add a new contact into the address book" << endl;
	cout << "     [2] Delete a contact from the address book" << endl;
	cout << "     [3] Modify a name or date in the address book" << endl;
	cout << "     [4] Generate a birthday card" << endl;
	cout << "     [5] Generate an anniversary card" << endl;
	cout << "     [6] Show contacts in address book" << endl;
	cout << "     [7] Exit the address book application (info will not be saved)" << endl;

	while (decide == false) {
		consoleInput();
	}
	system("cls");
}

void choiceOne() {
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                                Add Contact" << endl
		 << "-----------------------------------------------------------------------------" << endl;

	string newName;
	string newAddress;
	int bday;
	int bmonth;
	int byear;
	int aday;
	int amonth;
	int ayear;

	cout << "Enter Name:" << endl;
	getline(cin,newName);
	cout << "Enter address:" << endl;
	getline(cin, newAddress);
	cout << "Enter Birthday" << endl;
	cout << "Year: ";
	cin >> byear;
	cout << "Month: ";
	cin >> bmonth;
	cout << "Day: ";
	cin >> bday;
	cout << "Enter Anniversary" << endl;
	cout << "Year: ";
	cin >> ayear;
	cout << "Month: ";
	cin >> amonth;
	cout << "Day: ";
	cin >> aday;
	cin.ignore();
	
	book1.Insert(newName, newAddress, bday, bmonth, byear, aday, amonth, ayear);
	
	cout << endl << "Contact has been added!" << endl << endl;
	system("pause");
}

void choiceTwo() {
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                               Delete Contact" << endl
		 << "-----------------------------------------------------------------------------" << endl;
	string delName;
	cout << "Which contact do you want to delete from the address book?:" << endl;
	getline(cin, delName);
	book1.Delete(delName);
	system("pause");
}

void choiceThree() {
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                               Modify Contact" << endl
	   	 << "-----------------------------------------------------------------------------" << endl;
	string modName;

	cout << "Which contact do you want to modify in the address book?:" << endl;
	getline(cin, modName);

	book1.Modify(modName);
	
	system("pause");
}

void choiceFour() {
	int cfour;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                        Birthday Card Generator" << endl
		<< "-----------------------------------------------------------------------------" << endl << endl;

	cout << "Enter '1' to search for birthdays today" << endl;
	cout << "Enter '2' to search by month and day" << endl;
	cin >> cfour;

	if (cfour == 1) {
		book1.SearchBirthday(tday, tmonth);
	}
	else if (cfour == 2) {
		int m;
		int d;
		cout << endl << "Search Birthday:" << endl;
		cout << "Month: ";
		cin >> m;
		cout << "Day: ";
		cin >> d;
		book1.SearchBirthday(d, m);
	}
	else {
		cout << "Invalid Entry";
	}
	system("pause");
	cin.ignore();
}

void choiceFive() {
	int cfive;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                      Anniversary Card Generator" << endl
		<< "-----------------------------------------------------------------------------" << endl << endl;

	cout << "Enter '1' to search for anniversarries today" << endl;
	cout << "Enter '2' to search by month and day" << endl;
	cin >> cfive;

	if (cfive == 1) {
		book1.SearchAnniversary(tday, tmonth);
	}
	else if (cfive == 2) {
		int m;
		int d;
		cout << endl << "Search Anniversarry:" << endl;
		cout << "Month: ";
		cin >> m;
		cout << "Day: ";
		cin >> d;
		book1.SearchAnniversary(d, m);
	}
	else {
		cout << "Invalid Entry";
	}
	system("pause");
	cin.ignore();
}

void choiceSix() {
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                             Contact List" << endl
		 << "-----------------------------------------------------------------------------" << endl << endl;

	book1.PrintList();
	system("pause");
}

int main() {

	while (choice != 7) {

		prompt();

		if (choice == 1) {
			choiceOne();
		}
		if (choice == 2) {
			choiceTwo();
		}
		if (choice == 3) {
			choiceThree();
		}
		if (choice == 4) {
			choiceFour();
		}
		if (choice == 5) {
			choiceFive();
		}
		if (choice == 6) {
			choiceSix();
		}
		system("cls");

	}

	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "                                Goodbye!" << endl
		<< "-----------------------------------------------------------------------------" << endl << endl;

	system("pause");

	return 0;
}