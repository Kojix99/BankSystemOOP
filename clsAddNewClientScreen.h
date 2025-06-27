#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;


class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& NewClient)
	{
		cout << "\nEnter FirstName      : ";
		NewClient.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName       : ";
		NewClient.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email          : ";
		NewClient.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone          : ";
		NewClient.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode        : ";
		NewClient.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance : ";
		NewClient.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

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
	static void ShowAddnewClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\t  Add New Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Alrady Used: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_Print(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}
	}
};