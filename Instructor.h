#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include "User.h"

class Instructor :
public User
{
public:
	std::string setSchedule();
	void setSchedule(int groupNum);
private:

};

