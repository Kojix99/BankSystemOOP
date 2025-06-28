#pragma once
#include <iostream>
#include <iomanip>


#include "clsScreen.h"
#include "clsInputValidate.h"


#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"


using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionMenueOptions
    {
        eDeposit = 1,
        eWithdraw,
        eShowTotalBalance,
        eTransfer,
        eTransferLog,
        eShowMainMenueT
    };
    

    static short _ReadTransactionOption()
    {
        short TRANSACTION_OPTION_NUMBER = 6;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to " << TRANSACTION_OPTION_NUMBER << "] ? ";
        short TransactionOption = clsInputValidate::ReadShortNumberBetween(1, TRANSACTION_OPTION_NUMBER, "Enter Number between 1 to " + to_string(TRANSACTION_OPTION_NUMBER));
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

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::_ShowTransferLogScreen();
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
            case enTransactionMenueOptions::eTransfer:
            {
                system("cls");
                _ShowTransferScreen();
                _GoBackToTransactionMenue();
                break;
            }
            case enTransactionMenueOptions::eTransferLog:
            {
                system("cls");
                _ShowTransferLogScreen();
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
        
        cout << left;
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t\t\tTransaction Menue\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t[1] Deposite.\n";
        cout << setw(37) << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << "" << "\t[3] TotalBalances.\n";
        cout << setw(37) << "" << "\t[4] Transfer.\n";
        cout << setw(37) << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerformTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionOption());
	}
};