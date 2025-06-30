#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;


class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransferLogRegister(const clsBankClient::stTransferLog& TransferRegister)
    {
        cout << setw(8) << "" << "| " << setw(25) << TransferRegister.Date;
        cout << "| " << setw(10) << TransferRegister.SourceAccount;
        cout << "| " << setw(10) << TransferRegister.DestinationAccount;
        cout << "| " << setw(10) << TransferRegister.Amount;
        cout << "| " << setw(12) << TransferRegister.SourceBalance;
        cout << "| " << setw(12) << TransferRegister.DestinationBalance;
        cout << "| " << setw(12) << TransferRegister.UserName << endl;
    }
public:
	static void _ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLog> vTranferLog = clsBankClient::LoadTransferLogData();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t   (" + to_string(vTranferLog.size()) + ") Record(s).";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << left;
        cout << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________\n" << endl;

        cout << setw(8) << "" << "| " << setw(25) << "Date/Time";
        cout << "| " << setw(10) << "s.Acct";
        cout << "| " << setw(10) << "d.Acct";
        cout << "| " << setw(10) << "Amount";
        cout << "| " << setw(12) << "s.Balance";
        cout << "| " << setw(12) << "d.Balance";
        cout << "| " << setw(12) << "User";
        cout << setw(8) << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________\n" << endl;

        if (vTranferLog.size() == 0)
            cout << "\t\t\t\tNo Transfer Register Available In the System!";
        else
        { 
            for (const clsBankClient::stTransferLog& tempTransferRegister : vTranferLog)
            {
                _PrintTransferLogRegister(tempTransferRegister);
            }
        }  
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________\n" << endl;
	}
};