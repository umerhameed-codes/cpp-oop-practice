#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class  account {
	const int accountid;
	char *holdername;
	double balance;
	static int totalaccounts;
public:
	account();
	account(int id, const char *holdername, double balance);
	account(const account &acc);
	~account();
	account &deposit(double depositAmount);
	account &withdraw(double withdrawAmount);
	void display() const;
	static void displayTotalAccounts();
};
int account::totalaccounts = 0;
account :: account() :accountid(0) {
	holdername = new char[8];
	strcpy(holdername, "Unknown");
	balance = 0.0;
	totalaccounts++;
}
account::account(int id,const char *holdername, double balance) : accountid(id) {
	this->holdername = new char[strlen(holdername) + 1];
	strcpy(this->holdername, holdername);
	this->balance = balance;
	totalaccounts++;
}
account::account(const account &acc) : accountid(acc.accountid) {
	holdername = new char[strlen(acc.holdername) + 1];
	strcpy(holdername, acc.holdername);
	balance = acc.balance;
	totalaccounts++;
}
account::~account() {
	cout << "Account Destroyed " << accountid << "\n";
	delete[] holdername;
	totalaccounts--;
}
account& account::deposit(double depositAmount) {
	balance += depositAmount;
	return *this;
}
account& account::withdraw(double withdrawAmount) {
	if (withdrawAmount <= balance) {
		cout << "Amount Withdrawn.\n";
		balance -= withdrawAmount;
	}
	else {
		cout << "Insufficient Current Balance.\n";
	}
	return *this;
}
void account::display() const {
	cout << "Account ID: " << accountid << "\nAccount Holder's Name: " <<
		holdername << "\nCurrent Balance: " << balance << "\n\n";
}
void account::displayTotalAccounts() {
	cout << "Total Account: " << totalaccounts << endl;
}
int main() {
	account a;
	account a1(101, "Ali", 5000);
	account a2 = a1;
	cout << "Account with Default constructor:\n";
	a.display();
	cout << "Account with Parameterized Constructor:\n";
	a1.display();
	cout << "Account with copy constructor:\n";
	a2.display();
	// Doing Changings
	a1.deposit(1000).deposit(200);
	cout << "\n--------------- After Changings in A1---------------\n";
	a1.display();
	cout << "Is A2 still same:\n";
	a2.display();
	cout << endl;
	account::displayTotalAccounts();
	system("pause");
	return 0;
}

