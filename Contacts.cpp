#include <cstdlib>
#include <iostream>
#include <string>
#include "Contacts.h"
using namespace std;

//Initialize
Contacts::Contacts() {
	head = NULL;
	curr = NULL;
	temp = NULL;
	temp2 = NULL;
}

void Contacts::Delete(string delData) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	
	while (curr != NULL && curr->name != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << delData << " was not found in your contact list" << endl;
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << delData << " was removed from your address book" << endl;
	}
}

void Contacts::Modify(string modData) {
	int datanumber;
	string newvalue;
	int newnum;

	curr = head;
	temp = head;

	while (curr != NULL && curr->name != modData) {
			temp = curr;
			curr = curr->next;
		}
	if (curr == NULL) {
		cout << modData << " is not in your address book" << endl;
	}
	else {
		cout << endl << "Contact found!" << endl << endl;

		cout << "[" << curr->name << "]" << endl;
		cout << "Address: " << curr->address << endl;
		cout << "Birthday: " << curr->bday << " - " << curr->bmonth << " - " << curr->byear << endl;
		cout << "Anniversary: " << curr->aday << " - " << curr->amonth << " - " << curr->ayear << endl << endl;

		cout << "What would you like to modify?" << endl;

		cout << "[1] Name" << endl;
		cout << "[2] Address" << endl;
		cout << "[3] Bithday - Year" << endl;
		cout << "[4] Bithday - Month" << endl;
		cout << "[5] Bithday - Day" << endl;
		cout << "[6] Anniversary - Year" << endl;
		cout << "[7] Anniversary - Month" << endl;
		cout << "[8] Anniversary - Day" << endl;

		cout << endl << "Enter number" << endl;
		cin >> datanumber;
		system("cls");

		if (datanumber == 1) {		
			cin.ignore();
			cout << "New Name: " << endl;
			getline(cin, newvalue);
			curr->name = newvalue;

			if (curr != head) {
			temp->next = curr->next;
			curr->next = NULL;
			}
			if (curr == head) {
				head = curr->next;
			}
			
			temp2 = curr;
			temp2->next = NULL;

			if (head == NULL) {
				head = temp2;
			}
			else {
				curr = head;
				temp = NULL;
				while (curr != NULL) {
					if (curr->name >= temp2->name) {
						break;
					}
					else {
						temp = curr;
						curr = curr->next;
					}
				}
				if (curr == head) {
					temp2->next = head;
					head = temp2;
				}
				else {
					temp2->next = curr;
					temp->next = temp2;
				}
			}
		}
		else if (datanumber == 2) {
			cin.ignore();
			cout << "New Address: " << endl;
			getline(cin, newvalue);
			curr->address = newvalue;
		}
		else if (datanumber == 3) {
			cout << "New Birthday - Year: " << endl;
			cin >> newnum;
			curr->byear = newnum;
			cin.ignore();
		}
		else if (datanumber == 4) {
			cout << "New Birthday - Month: " << endl;
			cin >> newnum;
			curr->bmonth = newnum;
			cin.ignore();
		}
		else if (datanumber == 5) {
			cout << "New Birthday - Day: " << endl;
			cin >> newnum;
			curr->bday = newnum;
			cin.ignore();
		}
		else if (datanumber == 6) {
			cout << "New Anniversary - Year: " << endl;
			cin >> newnum;
			curr->ayear = newnum;
			cin.ignore();
		}
		else if (datanumber == 7) {
			cout << "New Anniversary - Month: " << endl;
			cin >> newnum;
			curr->amonth = newnum;
			cin.ignore();
		}
		else if (datanumber == 8) {
			cout << "New Anniversary - Day: " << endl;
			cin >> newnum;
			curr->aday = newnum;
			cin.ignore();
		}
		else {
			cout << "Invalid Entry" << endl;
			cin >> newnum;
			cin.ignore();
		} 
	}
}

void Contacts::PrintList() {
	curr = head;
	while (curr != NULL) {
		cout << "[" << curr->name << "]" << endl;
		cout << "Address: " << curr->address << endl;
		cout << "Birthday: " << curr->bday << " - " << curr->bmonth << " - " << curr->byear << endl;
		cout << "Anniversary: " << curr->aday << " - " << curr->amonth << " - " << curr->ayear << endl << endl;
		curr = curr->next;
	}
}

void Contacts::Insert(string name1, string add1, int day1, int month1, int year1, int day2, int month2, int year2) {
	nodePtr n = new node;
	n->name = name1;
	n->address = add1;
	n->bday = day1;
	n->bmonth = month1;
	n->byear = year1;
	n->aday = day2;
	n->amonth = month2;
	n->ayear = year2;
	
	n->next = NULL;
	
	if (head == NULL) {
		head = n;
	}
	else {
		curr = head;
		temp = NULL;
		while (curr != NULL) {
			if (curr->name >= n->name) {
				break;
			}
			else {
				temp = curr;
				curr = curr->next;
			}
		}
		if (curr == head) {
			n->next = head;
			head = n;
		}
		else {
			n->next = curr;
			temp->next = n;
		}
	}
}

void Contacts::SearchBirthday(int day, int month) {
	
	curr = head;
	
	while (curr != NULL) {
		if (curr->bday == day && curr->bmonth == month) {
			system("cls");
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "                       Happy Birthday " << curr->name << "!"                   << endl
				 << "     Thank you for being a special part of my life. I hope that you have     " << endl
				 << " a very special day. Four out of five people get money in their birthday     " << endl
				 << " cards. I guess you can now consider yourself lucky to be part of the 20%!   " << endl
				 << "                        with much love, Brady                                " << endl
				 << "-----------------------------------------------------------------------------" << endl;
			break;
		}
		else {
			curr = curr->next;
		}
	}

	if (curr == NULL) {
		cout << "None of your contacts have the birthday " << month << " - " << day << endl;
	}
}

void Contacts::SearchAnniversary(int day, int month) {
	curr = head;

	while (curr != NULL) {
		if (curr->aday == day && curr->amonth == month) {
			system("cls");
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "                        Happy Anniversary " << curr->name << "!" << endl
			 	 << "               I hope and pray that this would be an uplifting day           " << endl
				 << "                     with love and care from a rocking chair,                " << endl
				 << "                               your pal, Brady                               " << endl
				 << "-----------------------------------------------------------------------------" << endl;
			break;
		}
		else {
			curr = curr->next;
		}
	}

	if (curr == NULL) {
		cout << "None of your contacts have an anniversary on " << month << " - " << day << endl;
	}
}