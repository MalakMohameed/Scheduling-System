#pragma once

#include "User.h"
#include <Windows.h>

class Student :
    public User
{
public:
   std::vector<std::string> getStudentSubjects(std::string ID);
   std::string getStudentGPA(std::string ID);
   std::string getStudentName(std::string ID);
   void dropCourse(std::string ID, std::string courseCode);


private:


    std::string StudentDB[6][4] =
    {
        {"90","Saif ElDin Haitham","3.21","BAS111/SWE111/ENG101/ENT101"},
        {"91","Daniel Michel Sadek","3.31","BAS121/SWE111/ENG101/BAS111"},
        {"94","Malak Mohamed AbdelRazeq","4.5", "BAS111/SWE111/ENG101/ENT101"},
        {"95","Nour Amgad ", "3.6", "BAS111/SWE111/ENG101/ENT101"},
        {"93","Bassem Moussa", "2.9","BAS111/SWE210/BAS121/SWE111"},
        {"97", "a", "4.00","BAS111/SWE111/ENG101/ENT101" }
    };

};

