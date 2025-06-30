#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRate : protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency tempCurrency)
	{
		cout << "\nCurrency Card:";
		cout << "\n_______________________________\n";
		cout << "\nCountry    : " << tempCurrency.Country();
		cout << "\nCode       : " << tempCurrency.CurrencyCode();
		cout << "\nName       : " << tempCurrency.CurrencyName();
		cout << "\nRate(1$)   : " << tempCurrency.GetRate();
		cout << "\n_______________________________\n";

	}

	static float _ReadCurrencyRate()
	{
		float CurrencyRate;
		cout << "\n\nUpdate Currency Rate:\n";
		cout << "____________________________\n";
		CurrencyRate = clsInputValidate<float>::ReadData("Enter New Rate: ");

		return CurrencyRate;
	}

public:
	static void ShowUpdateCurrencyRateScreen()
	{
		clsScreen::_DrawScreenHeader("\tUpate Currency Screen");
		
		string CurrencyCode;
		cout << "Enter Currency Code: ";
		CurrencyCode = clsInputValidate<string>::ReadString();
		clsCurrency ToUpdateCurrency = clsCurrency::FindByCode(CurrencyCode);

		if (!ToUpdateCurrency.IsEmpty())
		{
			_PrintCurrencyCard(ToUpdateCurrency);

			char Answer;
			cout << "\nAre you sure you want to update rate of this Currency (Y/N): ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				float NewCurrencyRate = _ReadCurrencyRate();

				ToUpdateCurrency.UpdateRate(NewCurrencyRate);

				cout << "\n\nCurrency Rate Updated Successfully :-)\n";
				_PrintCurrencyCard(ToUpdateCurrency);

			}
			else
			{
				cout << "\nCurrency Rate does not updated.\n";
			}
		}
		else
		{
			cout << "Currency Does not Found.\n";
		}
		
	}
};