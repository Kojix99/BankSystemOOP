#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsUpdateClientScreen : protected clsScreen
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

	static void ShowUpdateClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		clsScreen::_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber;
		cout << "Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With [" << AccountNumber << "] Does not Exist, Enter Another One: ";
			AccountNumber = clsInputValidate::IsValideDate(AccountNumber);
		}

		clsBankClient ClientToUpdate = clsBankClient::Find(AccountNumber);

		_Print(ClientToUpdate);

		cout << "Are you sure you want to update this Client: ";
		char Answer;
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";
			_ReadClientInfo(ClientToUpdate);

			clsBankClient::enSaveResults SaveResults;
			SaveResults = ClientToUpdate.Save();

			switch (SaveResults)
			{
				case clsBankClient::enSaveResults::svSucceeded:
				{
					cout << "Client Updated Successfully.\n";
					_Print(ClientToUpdate);
					break;
				}
				case clsBankClient::enSaveResults::svFaildEmptyObject:
				{
					cout << "Client Is Empty.\n";
					break;
				}
			}
		}
		else
		{
			cout << "Client Does Not Updated Successfully.\n";
		}
	}
};