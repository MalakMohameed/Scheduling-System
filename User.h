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

	std::string StudentDB[8][3] =
	{   {"Saif","admin", "101513"},
		{"Daniel","admin"," 101514"},
		{"Yahia","admin"," 111513"},
		{"Bassem","admin","101513"},
		{"Malak","admin", "111513"},
		{"Nour","admin", "101513"},
		{"George", "admin", "101514"},
		{"a","a", " "}
	};

	std::string InstructorDB[9][2] =
	{   {"Salma Ahmad","instructor23"},
		{"Mariam Hossam","instructor24"},
		{"Hind Samy","teachingassistant30",},
		{"Khaled Mohamed ","teachingassistant31"},
		{"Mohamed Mohamed","instructor56"},
		{"Hany George","teachingassistant57"},
		{"Amira Salama","instructor11"},
		{"Dina Hosni","teachingassistant14"},
		{"Sara Youssef","instructor69"},
	};

};

//signed #1