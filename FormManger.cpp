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
	std::cout << "SetScrn Function Called\n";
	gui.removeAllWidgets();
	
	if (Usertype.equalIgnoreCase(UtInstructor))
	{
		
		std::cout << "aloo : " << scrnNo << std::endl;
		if (scrnNo.equalIgnoreCase(InstructorForms.one))
		{
			showInCreateMenu(gui);
			
			setScreenIndex(11);
			
		}
		else if (scrnNo==InstructorForms.two)
		{
		//	gui.loadWidgetsFromFile(InstructorForms.two);
			showInEditMenu(gui);
			setScreenIndex(12);
		}
		else if (scrnNo == InstructorForms.three)
		{
			//gui.loadWidgetsFromFile(InstructorForms.three);

			showInViewMenu(gui);

			setScreenIndex(13);
		}
		else 
		{
			showInMainMenu(gui);
			
		}
	}
	else if (Usertype.equalIgnoreCase(UtStudent))
	{
		gui.loadWidgetsFromFile(Form.Student);
		gui.get<tgui::Button>("USR_Button")->setText(User);
		gui.get<tgui::Button>("USR_Button")->onPress([&win] {system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUJcmljayByb2xs"); });

	}
	

}

void FormManger::showInMainMenu(tgui::GuiSFML& gui)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(Form.Instructor);
	gui.get<tgui::Button>("Create")->onPress([&] { 
		
		showInCreateMenu(gui);
		
		});
	gui.get<tgui::Button>("Edit")->onPress([&] {

		showInEditMenu(gui);

		});
	gui.get<tgui::Button>("View")->onPress([&] {

		showInViewMenu(gui);

		});
}
void FormManger::showInCreateMenu(tgui::GuiSFML& gui)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(InstructorForms.one);
	gui.get<tgui::Button>("Back_menu")->onPress([&] {
		
		showInMainMenu(gui);

		});
}
void FormManger::showInEditMenu(tgui::GuiSFML& gui)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(InstructorForms.two);
	gui.get<tgui::Button>("Back_menu")->onPress([&] {

		showInMainMenu(gui);

		});
}
void FormManger::showInViewMenu(tgui::GuiSFML& gui)
{
	gui.removeAllWidgets();
	gui.loadWidgetsFromFile(InstructorForms.three);
	gui.get<tgui::Button>("Back_menu")->onPress([&] {

		showInMainMenu(gui);

		});
}
//signed #1


