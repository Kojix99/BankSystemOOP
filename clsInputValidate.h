//Improve Project by Using Template instead of overloading

#pragma once
#include <iostream>
#include <iomanip>

#include "clsDate.h"

using namespace std;


template <typename T>

class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate DateToCompare, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1AfterDate2(From, To))
		{
			clsDate SwapDate = From;
			From = To;
			To = SwapDate;
		}
		return clsDate::IsDate1AfterDate2(DateToCompare, From) && clsDate::IsDate1BeforeDate2(DateToCompare, To);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);

		return S1;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static short ReadShortNumberBetween(short From = 0, short To = SHRT_MAX, string ErrorMessage = "")
	{
		short Number;
		while (!(cin >> Number) || Number < From || Number > To)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}

	static T ReadData(string Message)
	{
		T Data;
		if (!Message.empty())
		{
			cout << "\n" << Message;
		}

		while (!(cin >> Data))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!Message.empty())
			{
				cout << "\nInvalid Input .. " << Message;
			}
		}
		return Data;
	}

	static T ReadDataBetween(string Message, T from, T To, int SpaceNumber)
	{
		T Data;
		if (!Message.empty())
		{
			cout << left;
			cout << "\n" << setw(SpaceNumber) << "" << Message;
		}

		while (!(cin >> Data) || Data < from || Data > To)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!Message.empty())
			{
				cout << left;
				cout << "\n" << setw(SpaceNumber) << "";
				cout << "Invalid Input .. " << Message;    
			}
		}
		return Data;
	}
};