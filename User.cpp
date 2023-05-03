#include "User.h"

//std::string User::getPassWord()
//{
//	return Pass;
//}
//
//std::string User::getUsrName()
//{
//	return UsrName;
//}
//
//void User::setPassWord(std::string pass)
//{
//	Pass = pass;
//}
//
//void User::setUsrName(std::string usr)
//{
//	UsrName = usr;
//}
//
//void User::D_outputCred()
//{
//	 std::cout << "Username: " << getUsrName() << std::endl << "Password: " << getPassWord() << std::endl;
//}

bool User::validateLogin(std::string usr, std::string pass)
{
	std::cout << "FUNC CALL!\n";
	for (int i = 0; i < 7; i++)
	{
		if (usr==StudentDB[0][i] && pass == StudentDB[1][i])
		{
			//std::cout << "Login success!\n";
				return true;
			
		}
	}
	return false;
}
