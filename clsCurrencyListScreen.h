#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyListScreen : protected clsScreen
{
private:
    static void _PrintRecordLine(clsCurrency tempCurrency)
    {
        cout << setw(8) << left << "" << "| " << setw(26) << tempCurrency.Country()
            << "| " << setw(9) << tempCurrency.CurrencyCode()
            << "| " << setw(34) << tempCurrency.CurrencyName()
            << "| " << setw(20) << tempCurrency.GetRate();
    }

public:
	static void ShowCurrencyListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrencies.size()) + ") Currency.";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(26) << "Country"
            << "| " << setw(9) << "Code"
            << "| " << setw(34) << "Name;"
            << "| " << setw(20) << "Rate/(1$)"
            << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        for (clsCurrency& tempCurrency : vCurrencies)
        {

            _PrintRecordLine(tempCurrency);
            cout << endl;
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};