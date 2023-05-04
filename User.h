#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>

#pragma once
//
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

	std::string StudentDB[6][3] =
	{   {"Saif","admin", "101513"},
		{"Daniel","admin"," 101514"},
		{"Yahia","admin"," 111513"},
		{"Bassem","admin","101513"},
		{"Malak","admin", "111513"},
		{"Nour","admin", "101513"}
		

	};

};

//signed #1