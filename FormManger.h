#pragma once

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "User.h"
#include <Windows.h>
#include "Instructor.h"
#include "Student.h"
#include <fstream>
#include <iostream>


#define STUDENT_FORM_PATH "resources/St_Menu.txt"
#define INSTRUCTOR_FORM_PATH "resources/Inst_menu.txt"
#define LOGIN_FORM_PATH "resources/LoginScrnForm.txt"
#define IN_RECORD_FORM_PATH "resources/Inst_Create.txt"
#define IN_EDIT_FORM_PATH "resources/Inst_Edit.txt"
#define IN_VIEW_FORM_PATH "resources/Inst_View.txt"
#define ST_MYCOURSE_FORM_PATH "resources/St_Mycourses.txt"
//insert additional filepaths here 


class FormManger
{
private:
	
	int currentScreenIndex = 0;
	bool ManageAvil = false;
	

		void showInMainMenu(tgui::GuiSFML& gui, std::string Usr = NULL, std::string UsrId="");
		void showInCreateMenu(tgui::GuiSFML& gui, std::string Usr = NULL, std::string UsrId="");
		void showInEditMenu(tgui::GuiSFML& gui, std::string Usr=NULL, std::string UsrId="");
		void showInViewMenu(tgui::GuiSFML& gui, std::string Usr = NULL, std::string UsrId="");
		void showStMainMenu(tgui::GuiSFML& gui, std::string Usr = NULL, std::string UsrID = "");
		void showStCoursesMenu(tgui::GuiSFML& gui, std::string Usr = NULL, std::string UsrID = "");
	

	

public:
	
	const tgui::String UtInstructor = "IN";
	const tgui::String UtStudent = "ST";

	void setScreenIndex(int index);
	int getScreenIndex();

	//void login(tgui::String Usr, tgui::String Pass);

	

	struct
	{
		tgui::String  one = IN_RECORD_FORM_PATH;	//has Instructor Sub forms
		tgui::String  two = IN_EDIT_FORM_PATH;
		tgui::String  three = IN_VIEW_FORM_PATH;
	}  InstructorForms;
	struct 
	{
		tgui::String one = ST_MYCOURSE_FORM_PATH;	//has Student Sub forms
		tgui::String two = "";
	}StudentForms;
	
	struct 
	{
		tgui::String Login = LOGIN_FORM_PATH;

		tgui::String Student = STUDENT_FORM_PATH;

		tgui::String Instructor = INSTRUCTOR_FORM_PATH;
			
	}Form;


	
	void Setscreen(sf::RenderWindow& win, tgui::GuiSFML& gui, tgui::String User, tgui::String Usertype,std::string UserID ,tgui::String scrnNo=" ");

	
	
	
};

//Signed #16