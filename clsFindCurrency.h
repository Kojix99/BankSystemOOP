#pragma once

#include <iostream>


#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;


class clsFindCurrency : protected clsScreen
{
private:
	enum enFindByChoice
	{
		CurrencyCode = 1,
		CurrencyCountry
	};
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

	static void _ShowResults(clsCurrency FindCurrency)
	{
		if (clsCurrency::IsCurrencyExist(FindCurrency.Country()))
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(FindCurrency);
		}
		else
		{
			cout << "\nCurrency Does Not Found :-(\n";
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("\t Find Currency Screen");

		enFindByChoice Choice;
		Choice = enFindByChoice(clsInputValidate<short>::ReadDataBetween("Find By: [1] Code or [2] Country: ",1, 2, 0));


		if (Choice == enFindByChoice::CurrencyCode)
		{
			string CurrencyCode;
			cout << "\nEnter Currency Code: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency FindCurrency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(FindCurrency);
		}
		else
		{
			string CurrencyCountry;
			cout << "\nEnter Currency Country: ";
			CurrencyCountry = clsInputValidate<string>::ReadString();
			clsCurrency FindCurrency = clsCurrency::FindByCountry(CurrencyCountry);
			_ShowResults(FindCurrency);
		}
	}
};