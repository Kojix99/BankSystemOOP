#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"

#include "clsCurrencyListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyOptions
    {
        eListCurrencies = 1,
        eFindCurrency,
        eUpdateRate,
        eCurrencyCalculator,
        eMainMenueC
    };

    static enCurrencyOptions _ReadCurrencyOption()
    {
        short CURRENCY_OPTIONS_NUMBER = 5;
        
        short CurrencyOption;
        cout << left;
        cout << setw(37) << "" << "Choose what do you want to do [1 to " << CURRENCY_OPTIONS_NUMBER << "]: ";
        while (!(cin >> CurrencyOption) || CurrencyOption > CURRENCY_OPTIONS_NUMBER || CurrencyOption < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << setw(37) << "" << "Invalid Input .. Choose what do you want to do [1 to " << CURRENCY_OPTIONS_NUMBER << "]: ";
        }

        return enCurrencyOptions(CurrencyOption);
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrencyListScreen::ShowCurrencyListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
    }
    
    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculator()
    { 
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    
    static void _GoBackToCurrencyExchchanceScreen()
    {
        cout << "\n\n\n\t\t\tPress Any Key To Go Back To Currency Exchange Menue..";
        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _PerformCurrencyExchangeScreen(enCurrencyOptions CurrencyOption)
    {
        switch (CurrencyOption)
        {
            case enCurrencyOptions::eListCurrencies:
            {
                system("cls");
                _ShowListCurrenciesScreen();
                _GoBackToCurrencyExchchanceScreen();
                break;
            }
            case enCurrencyOptions::eFindCurrency:
            {
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyExchchanceScreen();
                break;
            }
            case enCurrencyOptions::eUpdateRate:
            {
                system("cls");
                _ShowUpdateRateScreen();
                _GoBackToCurrencyExchchanceScreen();
                break;
            }
            case enCurrencyOptions::eCurrencyCalculator:
            {
                system("cls");
                _ShowCurrencyCalculator();
                _GoBackToCurrencyExchchanceScreen();
                break;
            }
            case enCurrencyOptions::eMainMenueC:
            {
                //MainMenue Screen will handle this
                break;
            }
        }
    }
public:
	static void ShowCurrencyExchangeScreen()
	{
        system("cls");
        _DrawScreenHeader("  Currency Exchange Main Screen");
        
        cout << left;
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t Currency Exchange Menue\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerformCurrencyExchangeScreen(_ReadCurrencyOption());
	}
};