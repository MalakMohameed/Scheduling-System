//Signed by: Daniel #2

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
			gui.get<tgui::Button>("USR_Button")->onPress([&win] {system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUJcmljayByb2xs"); });
			
		}
		/*else if(CurrentUser.validateLogin(UsrName, Pass))
		{
			std::cout << "login Success!\n";
			win.create(sf::VideoMode(750, 750), "Instructor Advising");
			Fhndlr.Setscreen(win, gui, UsrName);
		}*/
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

