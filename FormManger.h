#pragma once

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>



#define STUDENT_FORM_PATH "resources/StudenetForm.txt"
#define INSTRUCTOR_FORM_PATH "resources/InstructorForm.txt"
#define LOGIN_FORM_PATH "resources/LoginScrnForm.txt"


class FormManger
{
private:
	const tgui::String UtInstructor = "IN";
	const tgui::String UtStudent = "ST";


public:

	
	struct 
	{
		tgui::String Login = LOGIN_FORM_PATH;

		tgui::String Student = STUDENT_FORM_PATH;

		tgui::String Instructor = INSTRUCTOR_FORM_PATH;
			
	}Form;

	
	void Setscreen(sf::RenderWindow& win, tgui::GuiSFML& gui, tgui::String User, tgui::String Usertype);
	
};

//Signed #1