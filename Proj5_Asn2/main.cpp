// Sam - Septembre 20 2026

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>


using namespace std;

#define PreRelease


#define STUDENT_FILE	"StudentData.txt"
#define STUDENT_EMAILS	"StudentData_Emails.txt"

typedef struct student
{
	string firstName;
	string lastName;

#ifdef PreRelease
	string email;

#endif // email only in PreRelease version

}STUDENT;

int main()
{
#ifdef PreRelease
	cout << "PreRelease Version" << endl;

#endif // end of PreRelease message


	STUDENT student;
	string line;

	vector<STUDENT> students;

#ifdef PreRelease
	ifstream StudentFile(STUDENT_EMAILS);

#else
	ifstream StudentFile(STUDENT_FILE);

#endif // end of PreRelease StudentData.txt file reading

	if (!StudentFile.is_open())
	{
		return 1;
	}
	else 
	{
		while (getline(StudentFile, line))
		{
			stringstream ss(line);
			getline(ss, student.firstName, ',');
			getline(ss, student.lastName, ',');
#ifdef PreRelease
			getline(ss, student.email);

#endif // end of PreRelease email reading

			//cout << "First Name: " << s1.firstName << ", Last Name: " << s1.lastName << endl;
			students.push_back(student);
		}
	}

#ifdef _DEBUG
	cout << "Number of students read: " << students.size() << endl;
	for (const STUDENT& s : students)
	{
#ifdef PreRelease
		cout << "First Name: " << s.firstName << ", Last Name: " << s.lastName << ", Email: " << s.email << endl;
	}
#else
		cout << "First Name: " << s.firstName << ", Last Name: " << s.lastName << endl;
	}
#endif
	 
#endif

	return 0;
}
