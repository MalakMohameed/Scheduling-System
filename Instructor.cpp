#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "Instructor.h"
#include <fstream>
#include <iomanip>
#include <TGUI/TGUI.hpp>
#include<string>
#include "FormManger.h"
#include "User.h"



void Instructor::writearray()
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
void Instructor::CreateSchedule(std::string instructorName, std::string ID, int days[30])
{
    std::ifstream Schedule("resources/Files/timetable.txt");
    std::ofstream schedule("resources/Files/timetable.txt", std::ios::app);
    std::string CheckUser;
    bool ScheduleExist = false;
    while (std::getline(Schedule, CheckUser))
    {
        if (CheckUser.find(instructorName + ID + ":") != std::string::npos)
        {
            ScheduleExist = true;
            std::cout << "User is Found!\n";
            break;
        }
    }
    Schedule.close();

    if (!ScheduleExist)
    {
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
    else
    {
        int MboxExistingData = MessageBoxA(nullptr, reinterpret_cast<LPCSTR>("\nThere is an existing data found for this user.\nYou can't create a new one."), reinterpret_cast<LPCSTR>("User Schedule already created"), MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
        schedule.close();


    }

}







int Instructor::ViewSchedule(std::string name, std::string ID)
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

    }

    if (check == true) {

        read.close();
    }
    else {
        std::cout << "User Not Found!\n";
        int MboxSubmitUserNotFound = MessageBoxA(nullptr, reinterpret_cast<LPCSTR>("\nThere isn't any data found for this user.\nFirst create a schedule."), reinterpret_cast<LPCSTR>("User Not Found"), MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
        return 0;
        
    }

}


static const int column = 6;
int timetable[5][column] = {
    {11, 21, 31, 41, 51, 61},
    {12, 22, 32, 42, 52, 62},
    {13, 23, 33, 43, 53, 63},
    {14, 24, 34, 44, 54, 64},
    {15, 25, 35, 45, 55, 65}
};
void saveTimetableValue(const std::string& checkboxName, int* values, const int& size)
{
    int checkboxIndex = std::stoi(checkboxName);
    int row = checkboxIndex / column;
    int col = checkboxIndex % column;
    int value = timetable[row][col];

    values[size] = value;
}


 int* Instructor::createCheckboxes(tgui::GuiSFML& gui)
 {
     static int selectedValues[30] = {}; // Declare a static array with size 30 and initialize all elements to 0

 for (int i = 0; i < 30; ++i)
 {
     auto checkbox = tgui::CheckBox::create();
     checkbox->setPosition(((i % 6) * 110) + 111, ((i / 6) * 60) + 255);
     checkbox->onCheck([i, this]() {
         saveTimetableValue(std::to_string(i), selectedValues, i);
         });
     checkbox->onUncheck([i, this]() {
         saveTimetableValue(std::to_string(i), selectedValues, i);
         });

     gui.add(checkbox);
 }

 // Return a pointer to the static array
 return selectedValues;
    }




 //Signed #13
