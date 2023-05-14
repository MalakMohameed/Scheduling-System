#pragma once

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "User.h"
#include <iostream>


#define STUDENT_FORM_PATH "resources/StudenetForm.txt"
#define INSTRUCTOR_FORM_PATH "resources/Inst_menu.txt"
#define LOGIN_FORM_PATH "resources/LoginScrnForm.txt"
#define IN_RECORD_FORM_PATH "resources/Inst_Create.txt"
#define IN_EDIT_FORM_PATH "resources/Inst_Edit.txt"
#define IN_VIEW_FORM_PATH "resources/Inst_View.txt"
//insert additional filepaths here 


class FormManger
{
private:
	
	int currentScreenIndex = 0;

	

		void showInMainMenu(tgui::GuiSFML& gui);
		void showInCreateMenu(tgui::GuiSFML& gui);
		void showInEditMenu(tgui::GuiSFML& gui);
		void showInViewMenu(tgui::GuiSFML& gui);

	

public:
	
	const tgui::String UtInstructor = "IN";
	const tgui::String UtStudent = "ST";

	void setScreenIndex(int index);
	int getScreenIndex();

	void login(tgui::String Usr, tgui::String Pass);

	

	struct
	{
		tgui::String  one = IN_RECORD_FORM_PATH;	//has Instructor Sub forms
		tgui::String  two = IN_EDIT_FORM_PATH;
		tgui::String  three = IN_VIEW_FORM_PATH;
	}  InstructorForms;
	struct 
	{
		tgui::String one = "";	//has Student Sub forms
		tgui::String two = "";
	}StudentForms;
	
	struct 
	{
		tgui::String Login = LOGIN_FORM_PATH;

		tgui::String Student = STUDENT_FORM_PATH;

		tgui::String Instructor = INSTRUCTOR_FORM_PATH;
			
	}Form;


	
	void Setscreen(sf::RenderWindow& win, tgui::GuiSFML& gui, tgui::String User, tgui::String Usertype, tgui::String scrnNo=" ");

	
	
	
};

//Signed #1