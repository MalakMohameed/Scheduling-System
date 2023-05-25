#pragma once

#include "FormManger.h"


Instructor schedule;


void FormManger::setScreenIndex(int index)
{
	currentScreenIndex = index;
	
}

int FormManger::getScreenIndex()
{
	return currentScreenIndex;
}

//void FormManger::login(tgui::String Usr, tgui::String Pass)
//{
//	
//}

void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype,std::string UserID ,tgui::String scrnNo)
{
	
	std::string usrName = User.toStdString();
	std::cout << "SetScrn Function Called\n";

	
	gui.removeAllWidgets();
	
	if (Usertype.equalIgnoreCase(UtInstructor))
	{
		std::ofstream schedule("resources/Files/timetable.txt", std::ios::app);
	
		if (scrnNo.equalIgnoreCase(InstructorForms.one))
		{
			showInCreateMenu(gui, usrName,UserID);
			
			setScreenIndex(1);
			
		}
		else if (scrnNo==InstructorForms.two)
		{
		
			showInEditMenu(gui,  usrName, UserID);
			setScreenIndex(12);
		}
		else if (scrnNo == InstructorForms.three)
		{
			

			showInViewMenu(gui, usrName, UserID);

			setScreenIndex(13);
			
		}
		else 
		{
			showInMainMenu(gui,usrName,UserID);
			
		}
	}
	else if (Usertype.equalIgnoreCase(UtStudent))
	{
		gui.loadWidgetsFromFile(Form.Student);
		gui.get<tgui::Button>("USR_Button")->setText(User);
		gui.get<tgui::Button>("USR_Button")->onPress([&win] {system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUJcmljayByb2xs"); });

	}
	

}

void FormManger::showInMainMenu(tgui::GuiSFML& gui, std::string Usr, std::string UsrID)
{
	
	gui.removeAllWidgets();
	
	gui.loadWidgetsFromFile(Form.Instructor);
	std::cout << "User ID: " << UsrID << std::endl;

	gui.get<tgui::Button>("Create")->onPress([=, &gui] {
		///just default input to check if it works or not and it will be changed later on 
		
		int days[2] = { 22,31 };/////////
		std::cout << "->" << Usr << std::endl;
	    
		showInCreateMenu(gui, Usr, UsrID);
		
		});
	gui.get<tgui::Button>("Edit")->onPress([=, &gui] {
	
		std::cout << "->" << Usr << std::endl;
		showInEditMenu(gui, Usr, UsrID);

		});
	gui.get<tgui::Button>("View")->onPress([=, &gui] {
		std::cout << "->" << Usr << std::endl;
	   
	    schedule.viewschedule(Usr, UsrID);
		showInViewMenu(gui, Usr, UsrID);
		});
}
void FormManger::showInCreateMenu(tgui::GuiSFML& gui, std::string Usr, std::string UsrID)
{
	
	std::cout << "\'showInCreateMenu()\' Function was called with User as: " << Usr <<std::endl;
	std::cout << "User ID: " << UsrID << std::endl;
	gui.removeAllWidgets();
	std::cout << "Widgets Removed\n";
	gui.loadWidgetsFromFile(InstructorForms.one);
	std::cout << "Widgets Loaded from file \n";
	int days[2] = { 22,31 };/////////
	schedule.writetimetable(Usr, UsrID, days);/////////

	gui.get<tgui::Button>("Back_menu")->onPress([=, &gui] {
		
		showInMainMenu(gui, Usr, UsrID);
		});

	gui.get<tgui::Button>("Submit")->onPress([&] {
		int MboxSubmitSuc = MessageBoxA(NULL, (LPCSTR)"\nYour submission has been saved succesfully!", (LPCSTR)"Submission", MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
		});
}


void FormManger::showInEditMenu(tgui::GuiSFML& gui, std::string Usr, std::string UsrId)
{
	std::cout << "\'showInEditMenu()\' Function was called with User as: " << Usr << std::endl;
	std::cout << "User ID: " << UsrId << std::endl;
	gui.removeAllWidgets();
	std::cout << "Widgets Removed\n";
	gui.loadWidgetsFromFile(InstructorForms.two);
	std::cout << "Widgets Loaded from file \n";
	gui.get<tgui::Button>("Back_menu")->onPress([=, &gui] {

		showInMainMenu(gui, Usr, UsrId);
		});

	gui.get<tgui::Button>("Submit")->onPress([&] {
		int MboxSubmitSuc = MessageBoxA(NULL, (LPCSTR)"\nYour submission has been saved succesfully!", (LPCSTR)"Submission", MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1);
		});

}


void FormManger::showInViewMenu(tgui::GuiSFML& gui, std::string Usr, std::string UsrId )
{
	std::cout << "\'showInViewMenu()\' Function was called with User as: " << Usr << std::endl;
	std::cout << "User ID: " << UsrId << std::endl;
	gui.removeAllWidgets();
	std::cout << "Widgets Removed\n";
	gui.loadWidgetsFromFile(InstructorForms.three);
	
	std::cout << "Widgets Loaded from file \n";
	schedule.viewschedule(Usr, UsrId);
	gui.get<tgui::Button>("Back_menu")->onPress([=, &gui] {
	
		showInMainMenu(gui, Usr, UsrId);
	    

		});
}
//Signed #10


