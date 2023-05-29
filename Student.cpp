#include "Student.h"

std::vector<std::string> Student::getStudentSubjects(std::string ID)
{
	std::cout << "getStudentSubjects Function called with ID: " << ID << '\n';
	std::string s, str;
	std::vector<std::string> courses(5);

	for (int i = 0; i < (sizeof(StudentDB) / sizeof(StudentDB[0][0])); i++)
	{
		if (StudentDB[i][0] == ID)
		{
			std::cout << "Student Found!\n";

			s = StudentDB[i][3];
			std::stringstream ss(s);
			for (int j = 0; j < 5; j++)
			{
				while (std::getline(ss, str, '/'))
				{
					std::cout << str << std::endl;
					courses[j] = str;
					break;
				}
			}

			return courses;

		}
		else std::cout << "Student Not In DataBase, Contact SSO\n";
	}

}

std::string Student::getStudentGPA(std::string ID)
{
	std::cout << "getStudentGPA Function called with ID: " << ID << '\n';
	for (int i = 0; i < (sizeof(StudentDB) / sizeof(StudentDB[0][0])); i++)
	{
		if (StudentDB[i][0] == ID)
		{
			std::cout << "Student GPA found:" << StudentDB[i][2] << '\n';
			return StudentDB[i][2];
		}
	}
}

std::string Student::getStudentName(std::string ID)
{
	for (int i = 0; i < (sizeof(StudentDB) / sizeof(StudentDB[0][0])); i++)
	{
		if (StudentDB[i][0] == ID)
		{
			std::cout << "Student Name Retrived : " << StudentDB[i][1] << std::endl;
			return StudentDB[i][1];

		}
	}
}

void Student::dropCourse(std::string ID, std::string courseCode)
{
	for (int i = 0; i < (sizeof(StudentDB) / sizeof(StudentDB[0][0])); i++)
	{
		if (StudentDB[i][0] == ID)
		{
			std::cout << courseCode << "Dropping\n";
			StudentDB[i][3].erase(StudentDB[i][3].find(courseCode), courseCode.length() + 1);
		}
	}
	std::stringstream box_message;
	int MboxSubmitSuc = MessageBoxA(NULL, (LPCSTR)"\nYour submission has been saved succesfully!\n", (LPCSTR)"Submission", MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);


}
//Signed #16