#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsWithdrawScreen : protected clsScreen
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
	static void ShowWithDrawScreen()
	{
		clsScreen::_DrawScreenHeader("\t    WithDrawScreen");

		string AccountNumber;
		cout << "\nEnter Accont Number: ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] Account Number does not exist, Enter another Account Number: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);

		float WithDrawAmount = clsInputValidate<float>::ReadDataBetween("Enter WithDraw Amount: ",0, FLT_MAX, 0);

		if (WithDrawAmount <= Client.AccountBalance)
		{
			cout << "\nAre you sure you want to With WithDraw [" << WithDrawAmount << "] this amount (Y/N): ";
			char Answer;
			cin >> Answer;
			if (tolower(Answer))
			{
				Client.WithDraw(WithDrawAmount);
				cout << "\nAmount Deposited Successfully.\n";
			}
			else
			{
				cout << "\nOperation was cancelled.\n";
			}
		}
		else
		{
			cout << "\nCannot withdraw, Insuffecient Balance!\n";
			cout << "\n\nAmount to withdraw is: " << WithDrawAmount;
			cout << "\n\nYour Balance is: " << Client.AccountBalance;
		}
	}
};