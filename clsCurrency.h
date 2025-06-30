#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "clsString.h"


using namespace std;


class clsCurrency
{
private:
	enum enMode {EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string CurrencyLine)
	{
		vector<string> vString = clsString::SplitByDelimiter(CurrencyLine, "#//#");


		return clsCurrency(enMode::UpdateMode, vString[0], vString[1],
			vString[2], stof(vString[3]));
	}

	static string _ConvertObjectToCurrencyLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string CurrencyLine = "";
		
		CurrencyLine += Currency.Country() + Seperator;
		CurrencyLine += Currency.CurrencyCode() + Seperator;
		CurrencyLine += Currency.CurrencyName() + Seperator;
		CurrencyLine += to_string(Currency.GetRate());

		return CurrencyLine;
	}

	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector<clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string CurrencyLine;
			while (getline(MyFile, CurrencyLine))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyObject(CurrencyLine));
			}

			MyFile.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrenciesToFile(const vector<clsCurrency>& vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			for (const clsCurrency& tempCurrency : vCurrencies)
			{
				MyFile << _ConvertObjectToCurrencyLine(tempCurrency) << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& tempCurrency : vCurrencies)
		{
			if (this->CurrencyCode() == tempCurrency.CurrencyCode())
			{
				tempCurrency = *this;
				break;
			}
		}

		_SaveCurrenciesToFile(vCurrencies);
		
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode,
		string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	bool IsEmpty()
	{
		return this->_Mode == enMode::EmptyMode;
	}

	string Country()
	{
		return this->_Country;
	}

	string CurrencyCode()
	{
		return this->_CurrencyCode;
	}

	string CurrencyName()
	{
		return this->_CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		this->_Rate = NewRate;
		this->_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllLetters(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string CurrencyLine;
			while (getline(MyFile, CurrencyLine))
			{
				clsCurrency tempCurrency = _ConvertLineToCurrencyObject(CurrencyLine);
				if (CurrencyCode == tempCurrency.CurrencyCode())
				{
					MyFile.close();
					return tempCurrency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllLetters(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string CurrencyLine;
			while (getline(MyFile, CurrencyLine))
			{
				clsCurrency tempCurrency = _ConvertLineToCurrencyObject(CurrencyLine);
				if (Country == clsString::UpperAllLetters(tempCurrency.Country()))
				{
					MyFile.close();
					return tempCurrency;
				}
			}
		}
		return _GetEmptyCurrencyObject();
	}

	float GetRate()
	{
		return this->_Rate;
	}

	static bool IsCurrencyExist(string Country)
	{
		clsCurrency tempCurrency = FindByCountry(Country);

		return (!(tempCurrency.IsEmpty()));
	}

	static bool IsCurrencyExistByCode(string CurrencyCode)
	{
		clsCurrency tempCurrency = FindByCode(CurrencyCode);

		return (!(tempCurrency.IsEmpty()));
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUsd(float Amount)
	{
		return (Amount / this->GetRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		return this->ConvertToUsd(Amount) * Currency2.GetRate();
	}
};