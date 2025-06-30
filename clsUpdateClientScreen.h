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
		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		cout << "\nEnter FirstName      : ";
		NewClient.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter LastName       : ";
		NewClient.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email          : ";
		NewClient.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone          : ";
		NewClient.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter PinCode        : ";
		NewClient.PinCode = clsInputValidate<string>::ReadString();

		NewClient.AccountBalance = clsInputValidate<float>::ReadData("Enter AccountBalance : ");
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
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With [" << AccountNumber << "] Does not Exist, Enter Another One: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient ClientToUpdate = clsBankClient::Find(AccountNumber);

		_Print(ClientToUpdate);

		cout << "\nAre you sure you want to update this Client(Y/N): ";
		char Answer;
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			_ReadClientInfo(ClientToUpdate);

			clsBankClient::enSaveResults SaveResults;
			SaveResults = ClientToUpdate.Save();

			switch (SaveResults)
			{
				case clsBankClient::enSaveResults::svSucceeded:
				{
					cout << "\nClient Updated Successfully.\n";
					_Print(ClientToUpdate);
					break;
				}
				case clsBankClient::enSaveResults::svFaildEmptyObject:
				{
					cout << "\nClient Is Empty.\n";
					break;
				}
			}
		}
		else
		{
			cout << "\nClient Does Not Updated.\n";
		}
	}
};