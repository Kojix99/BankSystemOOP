#pragma once
#include <iostream>
#include <iomanip>


#include "clsScreen.h"
#include "clsInputValidate.h"


#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"


using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionMenueOptions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eShowMainMenueT = 4
    };
    

    static short _ReadTransactionOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short TransactionOption = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4");
        return TransactionOption;
    }


    static void _ShowDepositeScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen()
    {
        clsWithdrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _GoBackToTransactionMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...";
        system("pause>0");
        ShowTransactionMenue();
    }

    static void _PerformTransactionMenueOption(enTransactionMenueOptions TransactionOption)
    {
        switch (TransactionOption)
        {
            case enTransactionMenueOptions::eDeposit:
            {
                system("cls");
                _ShowDepositeScreen();
                _GoBackToTransactionMenue();
                break;
            }
            case enTransactionMenueOptions::eWithdraw:
            {
                system("cls");
                _ShowWithDrawScreen();
                _GoBackToTransactionMenue();
                break;
            }
            case enTransactionMenueOptions::eShowTotalBalance:
            {
                system("cls");
                _ShowTotalBalanceScreen();
                _GoBackToTransactionMenue();
                break;
            }
            case enTransactionMenueOptions::eShowMainMenueT:
            {
                // Main Screen will Handle this by (showMainScreen)
                break;
            }
        }
    }
public:
	static void ShowTransactionMenue()
	{
        if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return;
        }
		system("cls");

		_DrawScreenHeader("\t\tTransaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] TotalBalances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionOption());
	}
};