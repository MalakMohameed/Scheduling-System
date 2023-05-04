#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>

#pragma once
//
class User
{
public:
	
	std::string getUsr();
	std::string getUserType();
	void setUsr(std::string Usrname);
	void setUserType(std::string UsrType);


	bool validateLogin(std::string usr, std::string pass);
	

private:
	std::string UsrName;
	std::string UserType;

	std::string UserDB[17][3] =
	{   {"Saif","admin",  "ST"},
		{"Daniel","admin","ST"},
		{"Yahia","admin", "ST"},
		{"Bassem","admin","ST"},
		{"Malak","admin", "ST"},
		{"Nour","admin",  "ST"},
		{"George","admin","ST"},
		{"a","a", "ST "},
		{"Salma Ahmad","instructor23",				"IN"},
		{"Mariam Hossam","instructor24",			"IN"},
		{"Hind Samy","teachingassistant30",			"IN"},
		{"Khaled Mohamed ","teachingassistant31",   "IN"},
		{"Mohamed Mohamed","instructor56",			"IN"},
		{"Hany George","teachingassistant57",		"IN"},
		{"Amira Salama","instructor11",				"IN"},
		{"Dina Hosni","teachingassistant14",		"IN"},
		{"Sara Youssef","instructor69",				"IN"}

	};

	

};

//signed #1