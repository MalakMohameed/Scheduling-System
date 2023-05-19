#include "FormManger.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include <iostream>
#include "User.h"
#include "Instructor.h"
#include "FormManger.h"

void FormManger::setScreenIndex(int index)
{
	currentScreenIndex = index;
}

int FormManger::getScreenIndex()
{
	return currentScreenIndex;
}

void FormManger::login(tgui::String Usr, tgui::String Pass)
{
	
}

void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype, tgui::String scrnNo)
{
	std::string usrName = User.toStdString();
	std::cout << "SetScrn Function Called\n";
	gui.removeAllWidgets();
	
	if (Usertype.equalIgnoreCase(UtInstructor))
	{
		
		std::cout << "aloo : " << scrnNo << std::endl;
		if (scrnNo.equalIgnoreCase(InstructorForms.one))
		{
			showInCreateMenu(gui, usrName);
			
			setScreenIndex(1);
			
		}
		else if (scrnNo==InstructorForms.two)
		{
		//	gui.loadWidgetsFromFile(InstructorForms.two);
			showInEditMenu(gui, usrName);
			setScreenIndex(12);
		}
		else if (scrnNo == InstructorForms.three)
		{
			//gui.loadWidgetsFromFile(InstructorForms.three);

			showInViewMenu(gui, usrName);

			setScreenIndex(13);
		}
		else 
		{
			showInMainMenu(gui,usrName);
			
		}
	}
	else if (Usertype.equalIgnoreCase(UtStudent))
	{
		gui.loadWidgetsFromFile(Form.Student);
		gui.get<tgui::Button>("USR_Button")->setText(User);
		gui.get<tgui::Button>("USR_Button")->onPress([&win] {system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUJcmljayByb2xs"); });

	}
	

}

void FormManger::showInMainMenu(tgui::GuiSFML& gui, std::string UsrName)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(Form.Instructor);
	gui.get<tgui::Button>("Create")->onPress([&] {
		std::cout << "ALO 1 is working\n";
		showInCreateMenu(gui, UsrName);
		std::cout << "ALO 2 is working\n";
	   // int days[4] = { 23,35,40,11 };
		//std::cout << "ALO 3 is working\n";
	//	Instructor table;
		//std::cout << "ALO 4 is working\n";
	  //  table.writetimetable(UsrName, 79, days);
		//std::cout << "ALO 5 is working\n";
		
		});
	gui.get<tgui::Button>("Edit")->onPress([&] {

		showInEditMenu(gui, UsrName);

		});
	gui.get<tgui::Button>("View")->onPress([&] {

		showInViewMenu(gui, UsrName);

		});
}
void FormManger::showInCreateMenu(tgui::GuiSFML& gui, std::string UsrName)
{
	std::cout << "\'showInCreateMenu()\' Function was called \n";
	gui.removeAllWidgets();
	std::cout << "Widgets Removed\n";
	gui.loadWidgetsFromFile(InstructorForms.one);
	std::cout << "Widgets Loaded from file \n";
	gui.get<tgui::Button>("Back_menu")->onPress([&] {
		
		showInMainMenu(gui,UsrName);
		});

	gui.get<tgui::Button>("Submit")->onPress([&] {
		int MboxSubmitSuc = MessageBoxA(NULL, (LPCSTR)"\nYour submission has been saved succesfully!", (LPCSTR)"Submission", MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
		});
}
void FormManger::showInEditMenu(tgui::GuiSFML& gui, std::string UsrName)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(InstructorForms.two);
	gui.get<tgui::Button>("Back_menu")->onPress([&] {

		showInMainMenu(gui, UsrName);
		});

	gui.get<tgui::Button>("Submit")->onPress([&] {
		int MboxSubmitSuc = MessageBoxA(NULL, (LPCSTR)"\nYour submission has been saved succesfully!", (LPCSTR)"Submission", MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
		});

}
void FormManger::showInViewMenu(tgui::GuiSFML& gui, std::string UsrName)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(InstructorForms.three);
	gui.get<tgui::Button>("Back_menu")->onPress([&] {

		showInMainMenu(gui, UsrName);

		});
}
//signed #1


