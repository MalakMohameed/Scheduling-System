#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>

#pragma once

class User
{
public:
	/*std::string getPassWord();
	std::string getUsrName();
	void setPassWord(std::string pass);
	void setUsrName(std::string usr);
	void D_outputCred();*/

	bool validateLogin(std::string usr, std::string pass);
	

private:
	std::string UsrName;
	std::string Pass;

	std::string StudentDB[2][6] =
	{ "Saif","admin"
		"Daniel","admin"
		"Yahia","admin"
		"Bassem","admin"
		"Malak","admin"
		"Nour","admin"
		

	};

};

