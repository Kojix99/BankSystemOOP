#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:
	static void ShowFindClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		clsScreen::_DrawScreenHeader("\tFind Client Screen");
		string AccountNumber;
		cout << "\nEnter Account Number To Find: ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] Account Number Does not Exist, Enter another Account Number: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient FindClient = clsBankClient::Find(AccountNumber);


		if (!FindClient.IsEmpty())
		{
			cout << "\nClient Found :)\n";
			_Print(FindClient);
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}
	}
};