//interface file
using namespace std;

class Contacts
{
public:
	Contacts();
	~Contacts(){};
	void Delete(string delData);
	void PrintList();
	void Insert(string name1, string add1, int day1, int month1, int year1, int day2, int month2, int year2);
	void Modify(string modData);
	void SearchBirthday(int day, int month);
	void SearchAnniversary(int day, int month);

private:
	typedef struct node {
		string name;
		string address;
		int bday;
		int bmonth;
		int byear;
		int aday;
		int amonth;
		int ayear;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	nodePtr temp2;
};

