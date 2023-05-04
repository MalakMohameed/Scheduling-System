#include "User.h"



std::string User::getUsr()
{
	return UsrName;
}

std::string User::getUserType()
{
	return UserType;
}

void User::setUsr(std::string Usrname)
{
	this->UsrName = Usrname;
}

void User::setUserType(std::string UsrType)
{
	this->UserType = UsrType;
}





bool User::validateLogin(std::string usr, std::string pass)
{
	std::cout << "FUNC CALL!\n";
	for (int i = 0; i < 18; i++)
	{
		 if (usr==UserDB[i][0] && pass == UserDB[i][1])
		{
			std::cout << " FUNC Login success!\n";
			setUsr(usr); setUserType(UserDB[i][2]);
				return true;
			
		}
	}
	return false;
}
//Signed #1