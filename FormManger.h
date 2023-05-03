#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
	
#pragma once

#define LOGIN_SCREEN_PATH "resources/LoginScrnForm.txt"
#define STUDENT_SCREEN_PATH "resources/StudenetForm.txt"

class FormManger
{
public:
	struct 
	{
		tgui::String Login = LOGIN_SCREEN_PATH;
		tgui::String Student = STUDENT_SCREEN_PATH;

	}Form;
};

