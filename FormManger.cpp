#include "FormManger.h"


void FormManger::Setscreen(sf::RenderWindow &win,tgui::GuiSFML &gui ,tgui::String User)
{
	gui.loadWidgetsFromFile(Form.Student, true);
	gui.get<tgui::Button>("USR_Button")->setText(User);
	//gui.loadWidgetsFromFile(Form.Instructor, true);

}
//signed #1