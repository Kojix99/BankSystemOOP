#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
	static short _ReadUserPermisions()
	{
		short Permissions = 0;

		short Counter = 1;

		char Answer;
		cout << "\n\nDo you want to gave full access: ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			return -1;
		}
		else
		{
			vector<string> vPermissions = {
			"\nShow Client List: ",
			"\nAdd New Client  : ",
			"\nDelete Client   : ",
			"\nUpdate Client   : ",
			"\nFind Client     : ",
			"\nTransactions    : ",
			"\nManage Users    : ",
			"\nLogin Register  : "
			};

			cout << "\nDo you want to gave access to:\n";
			cout << "\n_________________________________\n";
			for (short i = 0; i < vPermissions.size(); i++)
			{
				cout << vPermissions[i];
				cin >> Answer;
				if (tolower(Answer) == 'y')
				{
					Permissions += Counter;
				}
				Counter *= 2;
			}
			cout << "\n_________________________________\n";
		}
		
		return Permissions;

	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName       : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName        : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email           : ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone           : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password        : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions     : ";
		User.Permissions = _ReadUserPermisions();
	}

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

	static void ShowAddNewUserScreen()
	{
		clsScreen::_DrawScreenHeader("\tAdd New User Screen");
		string Username;;
		cout << "\nEnter User Name       : ";
		Username = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(Username))
		{
			cout << "User with Username [" << Username << "] Is already exist, Enter another UserName: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetAddNewUserObject(Username);

		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResults;

		SaveResults = User.Save();

		switch (SaveResults)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "Client saved Successfully.\n";
			_Print(User);
			break;
		}
		}
	}
};