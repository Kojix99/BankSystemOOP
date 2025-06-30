#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"



class clsDeleteUserScreen : protected clsScreen
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
	static void ShowDeleteUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t   Delete User Screen");

		string UserName;
		cout << "\nEnter User Name you want to Delete: ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser with [" << UserName << "] User Name Does not Exist, Enter Another UserName: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser UserToDelete = clsUser::Find(UserName);

		_Print(UserToDelete);

		cout << "\nAre you sure you want to delete this User (Y/N): ";
		char Answer;
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (UserToDelete.Delete())
			{
				cout << "\nClient Deleted Successfully.\n";
				_Print(UserToDelete);
			}
			else
			{
				cout << "\nClient does not Deleted.\n";
			}
		}
		else
		{
			cout << "\nClient Delete Option cancelled.\n";
		}
	}
};