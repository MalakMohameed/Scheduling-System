#include "FormManger.h"


void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype)
{
	
	gui.removeAllWidgets();
	if (Usertype.equalIgnoreCase(UtInstructor))
	{		
		try {
			std::cout << "\nLogged in as Instructor\n";
			gui.loadWidgetsFromFile(Form.Instructor);
		}
		catch (tgui::Exception &e)
		{
			std::cout << e.what() << std::endl << "Unable to load Instructor side Form File\n";
		}

	}

	else if (Usertype.equalIgnoreCase(UtStudent))
	{
		try {
			std::cout << "\nLogged in as Student\n";
			gui.loadWidgetsFromFile(Form.Student);
			gui.get<tgui::Button>("USR_Button")->setText(User);
		}
		catch (tgui::Exception &e)
		{
			std::cout << e.what() << std::endl << "Unable to load Student side Form file\n";
		}
	}

	else
		std::cout << "Invalid Login\n";
	

}
//signed #1