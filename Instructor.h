#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include<string>
#include "FormManger.h"
#include "User.h"



class Instructor :
	public User
{
   
public:
 
    Instructor();
	void writearray();
    void writetimetable(std::string instructorName, std::string ID, int days[30]);
    void viewschedule(std::string name, std::string ID);
private:
    static const int column = 6;
    int timetable[5][column] =
    { 11,21,31,41,51,61
     ,12,22,32,42,52,62
     ,13,23,33,43,53,63
     ,14,24,34,44,54,64
     ,15,25,35,45,55,65 };
};

