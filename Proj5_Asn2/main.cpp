// Sam - Septembre 20 2026

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>


using namespace std;

#define STUDENT_FILE	"StudentData.txt"
#define STUDENT_EMAILS	"StudentdData_Emails.txt"

typedef struct student
{
	string firstName;
	string lastName;
}STUDENT;

int main()
{

	STUDENT student;
	string line;

	vector<STUDENT> students;

	ifstream StudentFile(STUDENT_FILE);
	if (!StudentFile.is_open())
	{
		cout << "Error opening file: " << STUDENT_FILE << endl;
		return 1;
	}
	else 
	{
		while (getline(StudentFile, line))
		{
			stringstream ss(line);
			getline(ss, student.firstName, ',');
			getline(ss, student.lastName);
			//cout << "First Name: " << s1.firstName << ", Last Name: " << s1.lastName << endl;
			students.push_back(student);
		}
	}

#ifdef _DEBUG
	cout << "Number of students read: " << students.size() << endl;
	for (const STUDENT& s : students)
	{
		cout << "First Name: " << s.firstName << ", Last Name: " << s.lastName << endl;
	}
#endif

	return 0;
}
