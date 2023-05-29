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
bool Instructor::CheckInst(std::string instructorName, std::string ID)
{
    std::ifstream Schedule("resources/Files/timetable.txt");
    std::string CheckUser;
    bool ScheduleExist = false;
    while (std::getline(Schedule, CheckUser))
    {
        if (CheckUser.find(instructorName + ID + getInstructorSubject(ID) + ":") != std::string::npos)
        {
            ScheduleExist = true;
            std::cout << "User is Found!\n";
            break;
        }
    }
    return ScheduleExist;
}
void Instructor::CreateSchedule(std::string instructorName, std::string ID, int days[30])
{
    std::ifstream Schedule("resources/Files/timetable.txt");
    std::ofstream schedule("resources/Files/timetable.txt", std::ios::app);
    std::string CheckUser;
    std::string course = getInstructorSubject(ID);
    bool ScheduleExist = false;

    std::cout << course << "\n";
    while (std::getline(Schedule, CheckUser))
    {
        if (CheckUser.find(instructorName + ID + course + ":") != std::string::npos)
        {
            ScheduleExist = true;
            std::cout << "User is Found!\n";
            break;
        }
    }
    Schedule.close();

    if (!ScheduleExist)
    {
        schedule << instructorName << ID << course << ":\n";
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
int Instructor::ViewSchedule(std::string name, std::string ID, tgui::GuiSFML& gui)
{
    std::cout << "View schedule function was called by the user " << name + ID << '\n';
    std::ifstream read("resources/Files/timetable.txt");
    std::string output;
    bool check = false;
    int SelectedDays[30] = {};
    while (!read.eof())
    {
        getline(read, output);
        if (output.find(name + ID + getInstructorSubject(ID) + ":") != std::string::npos)
        {
            check = true;
            std::cout << "User Found!\n" << output << '\n';
            for (int i = 0; i < 30; i++) {
                read >> output;

                if (stoi(output) % 100 == stoi(ID) && stoi(output) / 100 != 0)
                {


                    SelectedDays[i] = stoi(output);

                }
                else if (stoi(output) == 65 || stoi(output) / 100 == 65)
                {
                    if (stoi(output) == 65)
                    {
                        break;
                    }
                    else if (stoi(output) / 100 == 65)
                    {

                        SelectedDays[i] = stoi(output);
                        break;

                    }
                }


            }

            break;
        }

    }

    if (check == true) {
        tgui::CheckBox::Ptr checkboxes[30];
        int checkboxIndex = 0;
        for (int i = 0; i < 30; i++) {

            SelectedDays[i]; // Example timetable value
            checkboxes[checkboxIndex] = tgui::CheckBox::create();
            checkboxes[checkboxIndex]->setPosition(((checkboxIndex % 6) * 110) + 111, ((checkboxIndex / 6) * 60) + 255);
            checkboxes[checkboxIndex]->setEnabled(false); // Make the checkboxes uneditable
            bool setCheck = (SelectedDays[i] != 0);
            checkboxes[checkboxIndex]->setChecked(setCheck);
            gui.add(checkboxes[checkboxIndex]);
            checkboxIndex++;

        }

        read.close();
    }
    return 0;
}


std::string Instructor::getInstructorSubject(std::string ID)
{
    std::cout << "getInstructorSubject Function called with ID: " << ID << '\n';
    std::string course;

    for (int i = 0; i < (sizeof(InstructorDB) / sizeof(InstructorDB[0][0])); i++)
    {
        if (InstructorDB[i][1] == ID)
        {
            std::cout << "Instructor Found!\n";
            course = InstructorDB[i][2];
            std::cout << course << "\n";

            return course;

        }
        else {
            std::cout << "Instructor Not In DataBase, Contact SSO\n";
        }
    }

}


//Signed #16
