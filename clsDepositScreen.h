#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;


class clsDepositScreen : protected clsScreen
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
	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t    Deposite Screen");
		string AccountNumber;
		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] Account Number does not exist,  Enter another account Number: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);

		float DepositAmount = clsInputValidate<float>::ReadDataBetween("Enter Deposite Amount: ", 0, FLT_MAX, 0);
		
		char Answer;

		cout << "\nAre you sure you want to Deposit [" << DepositAmount << "] this amount (Y/N): ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Client.Deposit(DepositAmount);
			cout << "\nAmount Deposited Succcessfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};