#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "Instructor.h"
#include <fstream>
#include <iomanip>




cInstructor::cInstructor() {

}


void cInstructor::writearray()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << timetable[i][j] << " ";
            count++;
            if (count % 6 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
}


void cInstructor::writetimetable(std::string instructorName, std::string ID, int days[30])
{
    std::ifstream Schedule("resources/Files/timetable.txt");
    std::ofstream schedule("resources/Files/timetable.txt",std::ios::app);
    std::string CheckUser;
    bool ScheduleExist = 0;


    while (!Schedule.eof())
    {
        getline(Schedule, CheckUser);
        if (CheckUser.find(instructorName + ID + ":") != std::string::npos) {
            ScheduleExist = 1;
            std::cout << "User is Found!\n";
            break;
        }

        else {
            ScheduleExist = 0;
        }
        
    }
    Schedule.close();

    if (ScheduleExist == 0) {
        schedule << instructorName << ID << ":\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < column; j++)
            {
                bool isChoiceDay = false;
                for (int k = 0; k < 30; k++)
                {
                    if (timetable[i][j] == days[k])
                    {
                        isChoiceDay = true;
                        break;
                    }
                }
                if (isChoiceDay)
                {
                    schedule << timetable[i][j] << ID << std::setw(6) << " ";
                }
                else
                {
                    schedule << timetable[i][j] << std::setw(8) << " ";

                }
                if ((j + 1) % 6 == 0)
                {
                    schedule << std::endl;
                }
            }
        }
        schedule << std::endl;
        schedule.close();
    }

    else if(ScheduleExist == 1) {
        int MboxExistingData = MessageBoxA(nullptr, reinterpret_cast<LPCSTR>("\nThere is an existing data found for this user.\n You can edit your schedule but you can't create a new one."), reinterpret_cast<LPCSTR>("User Not Found"), MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
        schedule.close();
        exit(0);
    }
        
}



void cInstructor::viewschedule(std::string name, std::string ID)
{
    std::cout << "View schedule function was called by the user " << name + ID << '\n';
    std::ifstream read("resources/Files/timetable.txt");
    std::string output;
    bool check = false;

    while (!read.eof())
    {
        getline(read, output);
        if (output.find(name + ID + ":") != std::string::npos)
        {
            check = true;
            std::cout << "User Found!\n" << output << '\n';
            for (int i = 0; i < 30; i++) {
                read >> output;

                if (stoi(output) % 100 == stoi(ID) && stoi(output) / 100 != 0)
                {
                    std::cout << output << std::endl;
                }
                else if (stoi(output) == 65 || stoi(output) / 100 == 65)
                {
                    if (stoi(output) == 65)
                    {
                        break;
                    }
                    else if (stoi(output) / 100 == 65)
                    {
                        std::cout << output << std::endl;
                        break;

                    }
                }


            }

            break;
        }

        else {
            continue;
        }
    }

    if (check == true) {

        read.close();
    }
    else {
        std::cout << "User Not Found!\n";
        int MboxSubmitUserNotFound = MessageBoxA(nullptr, reinterpret_cast<LPCSTR>("\nThere isn't any data found for this user.\nFirst create a schedule."), reinterpret_cast<LPCSTR>("User Not Found"), MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
        exit(0);
        read.close();
    }

}
//Signed #9