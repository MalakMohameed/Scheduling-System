#pragma once

#include "User.h"
#include "Instructor.h"
#include <Windows.h>

class Student :
    public User
{
public:
   std::vector<std::string> getStudentSubjects(std::string ID);
   std::string getStudentGPA(std::string ID);
   std::string getStudentName(std::string ID);
   void dropCourse(std::string ID, std::string courseCode);
  void createStSchdl(std::string ID,std::string course);


private:


    static const int column = 6;
    std::string STtimetable[5][column] =
    { {"11","21","31","41","51","61"}
     ,{"12","22","32","42","52","62" }
     ,{"13","23","33","43","53","63"}
     ,{"14","24","34","44","54","64"}
     ,{"15","25","35","45","55","65" }
};

    struct {
        sf::Vector2f Sun1 = sf::Vector2f(60,260);
        sf::Vector2f Sun2 = sf::Vector2f(60, 340);
        sf::Vector2f Sun3 = sf::Vector2f(60, 400);
        sf::Vector2f Sun4 = sf::Vector2f(60, 470);
        sf::Vector2f Sun5 = sf::Vector2f(60, 530);
        
        /// Monday Coords
       
        sf::Vector2f Mon1 = sf::Vector2f(60, 260);
        sf::Vector2f Mon2 = sf::Vector2f(60, 260);
        sf::Vector2f Mon3 = sf::Vector2f(60, 260);
        sf::Vector2f Mon4 = sf::Vector2f(60, 260);
        sf::Vector2f Mon5 = sf::Vector2f(60, 260);

        ///TuesdayCoords

        sf::Vector2f Tue1 = sf::Vector2f(60, 260);
        sf::Vector2f Tue2 = sf::Vector2f(60, 260);
        sf::Vector2f Tue3 = sf::Vector2f(60, 260);
        sf::Vector2f Tue4 = sf::Vector2f(60, 260);
        sf::Vector2f Tue5 = sf::Vector2f(60, 260);

        ///WednesdayCoords

        sf::Vector2f Wed1 = sf::Vector2f(60, 260);
        sf::Vector2f Wed2 = sf::Vector2f(60, 260);
        sf::Vector2f Wed3 = sf::Vector2f(60, 260);
        sf::Vector2f Wed4 = sf::Vector2f(60, 260);
        sf::Vector2f Wed5 = sf::Vector2f(60, 260);

    }StSchdlLabelCoord;

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
//Signed #16
