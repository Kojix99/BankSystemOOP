#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsUpdateUserScreen : protected clsScreen
{
private:
	static short _ReadUserPermisions()
	{
		short Permissions = 0;

		short Counter = 1;

		char Answer;
		cout << "\n\nDo you want to gave full access (Y/N): ";
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
			"\nManage Users    : "
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
	static void _ShowUpdateUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t   Update User Screen.");

		string UserName;
		cout << "Enter UserName to Update: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User with [" << UserName << "] Does not exist, Enter another UserName: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser UserToUpdate = clsUser::Find(UserName);

		_Print(UserToUpdate);

		char Answer;
		cout << "\nAre you sure you want to Update this User: ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			cout << "\n\nUpdate User Info: ";
			cout << "\n__________________________________\n";

			_ReadUserInfo(UserToUpdate);

			clsUser::enSaveResults SaveResult = UserToUpdate.Save();

			switch (SaveResult)
			{
				case clsUser::enSaveResults::svSucceeded:
				{
					cout << "\nUpdated User Saved Successfully.\n";
					_Print(UserToUpdate);

					break;
				}
				case clsUser::enSaveResults::svFaildEmptyObject:
				{
					cout << "Client Does Not Updated because it is Empty";
					break;
				}
			}
		}
		else
		{
			"\nUpdate Client Cancelled.\n";
		}
	}
};