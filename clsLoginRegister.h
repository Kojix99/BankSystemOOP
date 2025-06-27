#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsString.h"


using namespace std;

class clsLoginRegister : protected clsScreen
{
private:
    static void _PrintUserRecordLine(const clsUser::stLoginRegisterRecord& UserLoginRecord)
    {
        cout << setw(8) << "" << "| " << left << setw(30) << UserLoginRecord.DateTime;
        cout << "| " << setw(20) << UserLoginRecord.UserName;
        cout << "| " << setw(20) << UserLoginRecord.Password;
        cout << "| " << setw(14) << UserLoginRecord.Permissions << endl;;
    }

public:

	static void ShowLoginRegisterScreen()
	{
		clsScreen::_DrawScreenHeader("\t\tRegister Login Screen");

		vector<clsUser::stLoginRegisterRecord> vUsers = clsUser::LoadLoginRegisterUsers();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t\t  (" + to_string(vUsers.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << setw(20) << "UserName";
        cout << "| " << setw(20) << "Password";
        cout << "| " << setw(14) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users LogIn the System!";
        else
        {
            for (const clsUser::stLoginRegisterRecord& UserLoginResister : vUsers)
            {

                _PrintUserRecordLine(UserLoginResister);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        }
	}
};