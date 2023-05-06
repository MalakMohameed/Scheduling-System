#include "FormManger.h"


void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype)
{
	
	gui.removeAllWidgets();
	if (Usertype.equalIgnoreCase(UtInstructor))
	{		
		std::cout << "\nLogged in as Instructor\n";
		gui.loadWidgetsFromFile(Form.Instructor);
	}

	else if (Usertype.equalIgnoreCase(UtStudent))
	{

		std::cout << "\nLogged in as Student\n";
		gui.loadWidgetsFromFile(Form.Student);
		gui.get<tgui::Button>("USR_Button")->setText(User);
	}

	else
		std::cout << "Invalid Login\n";
	
	
	

}
//signed #1