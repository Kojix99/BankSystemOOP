#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;


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

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Try again: ")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Try again: ")
	{
		double Number;
		cout << "Enter a Number: ";
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string InvalidMessage = "Invalid Number, Try again: ")
	{
		int Number;
		cout << "Enter a Number: ";
		cin >> Number;
		while (cin.fail() || !IsNumberBetween(Number, From, To))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage;
			cin >> Number;
		}
		return Number;
	}

	static double ReadDblNumberBetween(int From, int To, string InvalidMessage)
	{
		double Number;
		cout << "Enter a Double: ";
		cin >> Number;
		while (cin.fail() || !IsNumberBetween(Number, (double)From, (double)To))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage;
			cin >> Number;
		}
		return Number;
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
};
