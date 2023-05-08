#include "FormManger.h"


void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype, tgui::String scrnNo)
{
	
	gui.removeAllWidgets();
	
	if (Usertype.equalIgnoreCase(UtInstructor))
	{
		std::cout << "aloo : " << scrnNo << std::endl;
		if (scrnNo.equalIgnoreCase(InstructorForms.one))
		{
			gui.loadWidgetsFromFile(InstructorForms.one);
		}
		else if (scrnNo==InstructorForms.two)
		{
			gui.loadWidgetsFromFile(InstructorForms.two);
		}
		else if (scrnNo == InstructorForms.three)
		{
			gui.loadWidgetsFromFile(InstructorForms.three);
		}
		else 
		{
			gui.loadWidgetsFromFile(Form.Instructor);
		}
	}
	else if (Usertype.equalIgnoreCase(UtStudent))
	{
		gui.loadWidgetsFromFile(Form.Student);

	}
	

}
//signed #1