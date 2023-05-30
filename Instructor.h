#pragma once
#include"User.h"


class Instructor :
    public User
{

public:
    void writearray();
    void CreateSchedule(std::string instructorName, std::string ID, int days[30]);
    bool CheckInst(std::string instructorName, std::string ID);
    int* createCheckboxes(tgui::GuiSFML& gui);
    std::string getInstructorSubject(std::string ID);
    int ViewSchedule(std::string name, std::string ID, tgui::GuiSFML& gui);
    std::string getInstructorSubjecCode(std::string CrsID);
   std::string getInstructorID(std::string CrsID);
    std::string getInstructorName(std::string CrsID);
    std::string* AvilableDays(std::string CrsID);

private:

    static const int column = 6;
    int timetable[5][column] =
    { 11,21,31,41,51,61
     ,12,22,32,42,52,62
     ,13,23,33,43,53,63
     ,14,24,34,44,54,64
     ,15,25,35,45,55,65 };

    std::string InstructorDB[10][3] =
    {
        {"b","98","MOM069"},
        {"Salma Ahmad","23"," EAP110"},
        {"Mariam Hossam","24"," ENG101"},
        {"Hind Samy","30"," BAS111"},
        {"Khaled Mohamed ","31"," BAS111"},
        {"Mohamed Mohamed","56"," CSC120"},
        {"Hany George","57"," CSC120"},
        {"Amira Salama","11"," SWE111"},
        {"Dina Hosni","14"," SWE111"},
        {"Sara Youssef","69"," ENR101"}

    };
};

//Signed #16