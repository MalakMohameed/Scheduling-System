#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>


//
class User
{
public:
	
	std::string getUsr();
	std::string getUserType();
    std::string getUserID();
	void setUsr(std::string Usrname);
	void setUserType(std::string UsrType);
    void setUserID(std::string UserID);

	bool isSignedIn();
	void setSignInState(bool state);

	bool validateLogin(std::string usr, std::string pass);
	

private:
	std::string UsrName;
	std::string UserType;
    std::string UserID;

	bool signedIn = false;

	std::string UserDB[18][4] =
	{   {"Saif","admin",  "ST","90"},
        {"Daniel","admin","ST","91"},
        {"Yahia","admin", "ST","92"},
        {"Bassem","admin","ST","93"},
        {"Malak","admin", "ST","94"},
        {"Nour","admin",  "ST","95"},
        {"George","admin","ST","96"},
        {"a","a", "ST","97"},
        {"b","b",    "IN","98"},
        {"Salma Ahmad","instructor23",                "IN","23"},
        {"Mariam Hossam","instructor24",            "IN","24"},
        {"Hind Samy","teachingassistant30",            "IN","30"},
        {"Khaled Mohamed ","teachingassistant31",   "IN","31"},
        {"Mohamed Mohamed","instructor56",            "IN","56"},
        {"Hany George","teachingassistant57",        "IN","57"},
        {"Amira Salama","instructor11",                "IN","11"},
        {"Dina Hosni","teachingassistant14",        "IN","14"},
        {"Sara Youssef","instructor69",                "IN","69"}

	};

	

};

//Signed #15