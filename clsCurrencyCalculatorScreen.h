#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static clsCurrency _ReadCurrency(string Message)
	{
		string Code;
		cout << Message;
		Code = clsInputValidate<string>::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		while (Currency.IsEmpty())
		{
			cout << "Invalid Input .. " << Message;
			Code = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(Code);
		}

		return Currency;
	}

	static float _ReadExchangeAmount()
	{
		float ExchangeAmount = clsInputValidate<float>::ReadData("Enter Amount To Exchange       : ");
		return ExchangeAmount;
	}

	static void _PrintCurrencyCard(clsCurrency tempCurrency, string Title = "Currency Card: ")
	{
		cout << "\n" << Title << "\n";
		cout << "\n_______________________________\n";
		cout << "\nCountry    : " << tempCurrency.Country();
		cout << "\nCode       : " << tempCurrency.CurrencyCode();
		cout << "\nName       : " << tempCurrency.CurrencyName();
		cout << "\nRate(1$)   : " << tempCurrency.GetRate();
		cout << "\n_______________________________\n\n";

	}

	static void _PrintCalculationResults(float Amount, clsCurrency SourceCurrency, clsCurrency DestinationCurrency)
	{
		_PrintCurrencyCard(SourceCurrency, "Convert From");

		float AmountInUSD = SourceCurrency.ConvertToUsd(Amount);

		cout << Amount << " " << SourceCurrency.CurrencyCode() <<
			" = " << AmountInUSD << "USD\n";

		if (DestinationCurrency.CurrencyName() == "USD")
		{
			return;
		}

		cout << "\n\nConvertring from USD to:\n";

		_PrintCurrencyCard(DestinationCurrency, "To: ");

		cout << Amount << " " << SourceCurrency.CurrencyCode() <<
			" = " << SourceCurrency.ConvertToOtherCurrency(Amount, DestinationCurrency) 
			<< DestinationCurrency.CurrencyCode();
	}
public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer;
		do
		{
			system("cls");
			clsScreen::_DrawScreenHeader("\t Update Currency Screen");

			clsCurrency SourceCurrency = _ReadCurrency("\nEnter Source Currency Code     : ");
			clsCurrency DestinationCurrency = _ReadCurrency("\nEnter Destination Currency Code: ");
															
			float ExchangeAmount = _ReadExchangeAmount();

			_PrintCalculationResults(ExchangeAmount, SourceCurrency, DestinationCurrency);
			cout << "\n\nDo you want to perform another calculation (Y/N): ";
			cin >> Answer;
		} while (tolower(Answer) == 'y');
	}
};

