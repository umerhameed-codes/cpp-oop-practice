#include<iostream>
#include<string>
using namespace std;
class student {
	int rollno;
	string name;
	float marks;
	static int totalstudents;
public:
	void input();
	void display() const;
	int getrollno() const;
	void updatemarks(float marks);
	static void displaytotalstudents();
	~student() {
		cout << "Student Destroyed " << rollno << endl;
	}
};
int student::totalstudents = 0;
void student::input() {
	cout << "Enter Roll no: ";
	cin >> rollno;
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Marks: ";
	cin >> marks;
	totalstudents++;
}
void student::display() const {
	cout << "Roll no: " << rollno << "\nName: " << name <<
		"\nMarks: " << marks << "\n\n";
}
int student::getrollno() const {
	return rollno;
}
void student::updatemarks(float marks) {
	this->marks = marks;
}
void student::displaytotalstudents() {
	cout << "Total Students: " << totalstudents << endl;
}
int main() {
	student s[50];
	int count = 0;
	while (true) {
		cout << "=========== Menu ===========\n";
		cout << "1- Add Student.\n" << "2- Display Students.\n" <<
			"3- Search Student.\n" << "4- Update Marks.\n" << "5- Exit";
		int choice;
		cout << "\nEnter Choice (1-5): ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (count >= 50) {
				cout << "Space Already full\n";
				break;
			}
			cout << "Enter Data of student " << count + 1 << ":\n";
			s[count].input();
			count++;
			break;
		case 2:
			for (int i = 0; i < count; ++i) {
				cout << "Student " << i + 1 << ":\n";
				s[i].display();
			}
			break;
		case 3:{
			int rollno;
			cout << "Enter Roll no to search student: ";
			cin >> rollno;
			bool found = false;
			for (int i = 0; i < count; ++i) {
				if (s[i].getrollno() == rollno) {
					found = true;
					cout << "Student Found.\n";
					s[i].display();
					break;
				}
			}
			if (!found) {
				cout << "Student Not found.\n";
			}
			break;
		}
		case 4: {
			int searchrollno;
			float newmarks;
			cout << "Enter Roll no: ";
			cin >> searchrollno;
			cout << "Enter New Marks: ";
			cin >> newmarks;
			bool studentfound = false;
			for (int i = 0; i < count; ++i) {
				if (s[i].getrollno() == searchrollno) {
					studentfound = true;
					s[i].updatemarks(newmarks);
					cout << "After Changing in Marks:\n";
					s[i].display();
					break;
				}
			}
			if (!studentfound) {
				cout << "Student Not found.\n";
			}
			break; 
		}
		case 5:
			student::displaytotalstudents();
			system("pause");
			return 0;
		}
	}
	
	system("pause");
	return 0;
}
