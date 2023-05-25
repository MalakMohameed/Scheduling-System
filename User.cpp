#include "User.h"



std::string User::getUsr()
{
	return UsrName;
}

std::string User::getUserType()
{
	
	return UserType;
}

std::string User::getUserID()
{
	return UserID;
}

void User::setUsr(std::string Usrname)
{
	this->UsrName = Usrname;
}

void User::setUserType(std::string UsrType)
{
	this->UserType = UsrType;
}

void User::setUserID(std::string UserID)
{
	this->UserID = UserID;
}

bool User::isSignedIn()
{
	if (signedIn)
		return true;
	else
		return false;
}

void User::setSignInState(bool state)
{
	signedIn = state;
}





bool User::validateLogin(std::string usr, std::string pass)
{
	std::cout << "FUNC CALL!\n";
	for (int i = 0; i < 19; i++)
	{
		 if (usr==UserDB[i][0] && pass == UserDB[i][1])
		{
			std::cout << " FUNC Login success!\n";
			setUsr(usr); setUserType(UserDB[i][2]); setUserID(UserDB[i][3]);
				return true;
			
		}
	}
	return false;
}
//Signed #10