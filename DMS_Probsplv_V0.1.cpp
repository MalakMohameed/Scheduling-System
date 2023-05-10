//Signed by: Daniel #4

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include <iostream>
#include "User.h"
#include "FormManger.h"

User CurrentUser;
FormManger Fhndlr;
//
int main()
{	
	//George was here
	sf::RenderWindow win(sf::VideoMode(750, 400), "Login", sf::Style::None);
	tgui::GuiSFML gui{ win };


	tgui::Theme greyTheme;
	greyTheme.load("resources/TransparentGrey.txt");	


	gui.loadWidgetsFromFile(Fhndlr.Form.Login);

	

	gui.get<tgui::Button>("Button1")->onPress([&gui, &win] {

		std::string UsrName = gui.get<tgui::EditBox>("EditBox1")->getText().toStdString();
		std::string Pass = gui.get<tgui::EditBox>("EditBox2")->getText().toStdString();

			
		if (CurrentUser.validateLogin(UsrName,Pass))
		{
			std::string Usertype = CurrentUser.getUserType();
			std::cout << "login Success!\n";
			win.create(sf::VideoMode(750, 750), "Student Advising");
			Fhndlr.Setscreen(win, gui, UsrName, Usertype);
		
			//	!BREAKS CODE! DONT REMOVE, WIP.	->	//	gui.get<tgui::Button>("USR_Button")->onPress([&win] {system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUJcmljayByb2xs"); });
			
		}
	
		else
		{
			int MboxFailLogin1 = MessageBoxA(NULL, (LPCSTR)"Login failed\n Username or Password incorrect", (LPCSTR)"Login Error", MB_ICONWARNING | MB_RETRYCANCEL | MB_DEFBUTTON1);
			
			switch (MboxFailLogin1)
			{
			case IDCANCEL:
				win.close();
			default:
				break;
			}
		}

		std::cout << "Hena b2a\n";


		if (CurrentUser.getUserType() == Fhndlr.UtInstructor)								//Instructor Screens and SubScreens code
		{
			std::cout << "User OPERATOR is a: " << CurrentUser.getUserType() << std::endl;

			gui.get<tgui::Button>("Create")->onPress([&gui, &win] {

				std::cout << "Create button was clicked!\n";
			Fhndlr.Setscreen(win, gui, CurrentUser.getUsr(), CurrentUser.getUserType(), Fhndlr.InstructorForms.one);

				});
			gui.get<tgui::Button>("Edit")->onPress([&gui, &win] {

				std::cout << "Edit button was clicked!\n";
			Fhndlr.Setscreen(win, gui, CurrentUser.getUsr(), CurrentUser.getUserType(), Fhndlr.InstructorForms.two);

				});
			gui.get<tgui::Button>("View")->onPress([&gui, &win] {

				std::cout << "View button was clicked!\n";
			Fhndlr.Setscreen(win, gui, CurrentUser.getUsr(), CurrentUser.getUserType(), Fhndlr.InstructorForms.three);

				});
		}
		else if (CurrentUser.getUserType() == Fhndlr.UtStudent)								//Student Screens and SubScreens code
		{
			gui.get<tgui::Button>("USR_Button")->onPress([&win] {system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUJcmljayByb2xs"); });

		}


		});

	


	



	while (win.isOpen())
	{
		sf::Event ev;
		
		while (win.pollEvent(ev))
		{
			gui.handleEvent(ev);
			if (ev.type == sf::Event::Closed)
			{
				win.close();
			}
		}


		win.clear();	
		gui.draw();
		win.display();

	}
}

