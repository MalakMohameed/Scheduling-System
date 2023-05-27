#pragma once
#include"User.h"


class Instructor :
	public User
{
   
public:
	void writearray();
    void CreateSchedule(std::string instructorName, std::string ID, int days[30]);
    int ViewSchedule(std::string name, std::string ID);
    int* createCheckboxes(tgui::GuiSFML& gui);
    int ViewSchedule(std::string name, std::string ID, tgui::GuiSFML& gui);
private:
    static const int column = 6;
    int timetable[5][column] =
    { 11,21,31,41,51,61
     ,12,22,32,42,52,62
     ,13,23,33,43,53,63
     ,14,24,34,44,54,64
     ,15,25,35,45,55,65 };
};
//Signed #14
