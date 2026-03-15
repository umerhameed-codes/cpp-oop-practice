#include<iostream>
#include<string>
using namespace std;
class student {
	int rollno;
	string name;
	float marks;
public:
	student();
	student(int rollno, const string& name, float marks);
	student(const student &s);
	student& updateMarks(float marks);
	void display() const;
	~student();
};
student :: student() {
	rollno = 0;
	name = "Unknown";
	marks = 0.0;
}
student::student(int rollno, const string& name, float marks) {
	this->rollno = rollno;
	this->name = name;
	this->marks = marks;
}
student::student(const student &s) {
	rollno = s.rollno;
	name = s.name;
	marks = s.marks;
}
student& student::updateMarks(float marks) {
	this->marks = marks;
	return *this;
}
void student::display() const {
	cout << "Roll NO: " << rollno << "\nName: "
		<< name << "\nMarks: " << marks << "\n\n";
}
student :: ~student() {
	cout << "Student Destroyed " << rollno << endl;
}
int main() {
	student s1;
	student s2(2432, "Umer Hameed", 98.4);
	student s3 = s2;
	cout << "Student with Default constructor:\n";
	s1.display();
	cout << "Student with Parameterized Constructor:\n";
	s2.display();
	cout << "Student with copy constrcutor:\n";
	s3.display();
	//Doing changes in Marks
	s2.updateMarks(87.6).updateMarks(77.7);
	cout << "\n=============== After Changing ===============\n";
	s2.display();
	system("pause");
	return 0;
}
