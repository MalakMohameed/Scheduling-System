#include "FormManger.h"


void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User, tgui::String Usertype, tgui::String scrnNo)	
{
	
	gui.removeAllWidgets();
	
	if (Usertype.equalIgnoreCase(UtInstructor))
	{
		if (scrnNo == InstructorForms.one)
		{
			//load form Instructor 1
		}
		else if (scrnNo==InstructorForms.two)
		{
			//load form Instructor 2
		}
	}
	else if (Usertype.equalIgnoreCase(UtStudent))
	{
		//repeat what was done with Instructor form loader
	}
	

}
//signed #1