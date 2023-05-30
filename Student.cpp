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

void Student::createStSchdl(std::string ID, std::string course)
{
	Instructor instructor;
	char buffer[5000];
	std::string CrsINAvilDays[5][6];
	int* ay7aga =  instructor.AvilableDays(course);
	std:: cout<< ay7aga << "\n";

	//for (int i =0; i < 5; i++)
	//{
	//	for (int j =0; j<6; j++)
	//	{
	//		for (int k =0; k < 30 ;k++)
	//		{
	//			sprintf_s(buffer, sizeof(buffer), "%d", ay7aga[k]);
	//			CrsINAvilDays[i][j] = buffer;
	//		}
	//	}
	//}


	std::cout << "Course: " << course << '\n';
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((STtimetable[i][j].length() == 2) && (CrsINAvilDays[j][i] != std::string("0")))
			{
				std::cout << "Student free on Day: " << i << "Slot " << j << '\n';
			}
		}

	}
	
}

//Signed #16