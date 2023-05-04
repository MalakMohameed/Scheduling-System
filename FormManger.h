#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
	//
#pragma once

#define LOGIN_SCREEN_PATH "resources/LoginScrnForm.txt"
#define STUDENT_SCREEN_PATH "resources/StudenetForm.txt"

class FormManger
{
private:



public:
	struct 
	{
		tgui::String Login = LOGIN_SCREEN_PATH;
		tgui::String Student = STUDENT_SCREEN_PATH;

	}Form;

	void Setscreen(sf::RenderWindow& win, tgui::GuiSFML &gui,tgui::String User);


};

