#pragma once



#include "User.h"




class Instructor :
	public User
{
   
public:
 
   
	void writearray();
    void writetimetable(std::string instructorName, std::string ID, int days[]);
    void viewschedule(std::string name, std::string ID);
private:
     static const int column = 6;
    int timetable[5][column] =
    { 11,21,31,41,51,61
     ,12,22,32,42,52,6
     ,13,23,33,43,53,63
     ,14,24,34,44,54,64
     ,15,25,35,45,55,65 };
};
//Signed #10