#include "FormManger.h"


void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype)
{
	if (Usertype == "IN")
	{
		std::cout << "\nLogged in as Instructor\n";
		gui.loadWidgetsFromFile(Form.Instructor, true);
		
	}
	else 
	{
		std::cout << "\nLogged in as Student\n";
		gui.loadWidgetsFromFile(Form.Student, true);
		gui.get<tgui::Button>("USR_Button")->setText(User);
		
	}

	
	

}
//signed #1