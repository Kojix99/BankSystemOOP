#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;


class clsFindUserScreen : protected clsScreen
{
private:
	static void _Print(clsUser& User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

public:
	static void _ShowFindUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t   Find User Screen");

		string UserName;
		cout << "\nEnter User Name: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser with [" << UserName << "] User Name does not exist, Enter Another UserName: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser UserToFind = clsUser::Find(UserName);

		cout << "\nUser Found :-)\n";

		_Print(UserToFind);
	}
};