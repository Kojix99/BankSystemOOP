#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"


#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreens.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyExchangeScreen.h"

//#include "Global.h"
#include "clsUser.h"


using namespace std;  

class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1,
        eAddNewClient,
        eDeleteClient,
        eUpdateClient,
        eFindClient, 
        eShowTransactionsMenue,
        eManageUsers,
        eLoginRegister,
        eCurrencyExchange,
        eExit
    };

    static enMainMenueOptions _ReadMainMenueOption()
    {
        short MAIN_MENUE_OPTIONS_NUMBER = 10;

        string Message = "Choose what do you want to do [1 to " + to_string(MAIN_MENUE_OPTIONS_NUMBER) + "]: ";
        short CurrencyOption = clsInputValidate<short>::ReadDataBetween(Message, 1, MAIN_MENUE_OPTIONS_NUMBER, 37);
       
        return enMainMenueOptions(CurrencyOption);
    }

    static  void _GoBackToMainMenue()
    {
        cout << "\n\n\tPress any key to go back to Main Menue...";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddnewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionMenue();
    }

    static void _ShowManageUsersMenue()
    {
       
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegister::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }

public:
    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t     Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << "" << "\t\t    Main Menue\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << "" << "\t[5] Find Client.\n";
        cout << setw(37) << "" << "\t[6] Transactions.\n";
        cout << setw(37) << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << "" << "\t[8] Login Register.\n";
        cout << setw(37) << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << "" << "\t[10] Logout.\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerfromMainMenueOption(_ReadMainMenueOption());
    }

};