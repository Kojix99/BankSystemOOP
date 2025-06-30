#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short _Tries = 3;
		string UserName, Password;
		do
		{
			if (LoginFaild)
			{
				cout << "\nInvalid Username/Password.\n";
				_Tries--;
				cout << "You have " << _Tries << " Trals to login.\n";
			}
			if (_Tries == 0)
			{
				cout << "\nYou are locked after 3 fails trails.\n\n";
				return false;
			}
			cout << "Enter UserName: ";
			UserName = clsInputValidate<string>::ReadString();
			
			cout << "Enter Password: ";
			Password = clsInputValidate<string>::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t    Login Screen");
		return _Login();
	}
};