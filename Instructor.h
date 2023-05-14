#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include "FormManger.h"
#include "User.h"

FormManger Fhndlr;

class Instructor :
public User
{
public:
	std::string setSchedule();
	void setSchedule(int groupNum);
	
	void Create();

private:

};

