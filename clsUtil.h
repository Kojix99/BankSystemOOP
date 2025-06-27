#pragma once
#include <iostream>
#include <climits>

using namespace std;


class clsUtil
{
private:
	static char GetSmallletter()
	{
		return char(RandomNumber('a', 'z'));
	}
	static char GetCapitalLetter()
	{
		return char(RandomNumber('A', 'Z'));
	}
	static char GetDigit()
	{
		return char(RandomNumber('0', '9'));
	}
	static char GetSpecialChar()
	{
		return RandomNumber('!', '/');
	}

public:
	static void Srand()
	{
		srand(unsigned(time(NULL)));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	enum enCharChoice
	{
		enSmallLetter = 1,
		enCapitalLetter = 2,
		enDigit = 3,
		enSpecialChar = 4,
		enMixChars = 5
	};

	static char GetRandomCharacter(enCharChoice CharChoice)
	{
		if (CharChoice == enCharChoice::enMixChars)
		{
			CharChoice = enCharChoice(RandomNumber(1, 3));
		}
		switch (CharChoice)
		{
		case enCharChoice::enSmallLetter:
			return GetSmallletter();

		case enCharChoice::enCapitalLetter:
			return GetCapitalLetter();

		case enCharChoice::enDigit:
			return GetDigit();

		case enCharChoice::enSpecialChar:
			return GetSpecialChar();

		default:
			return GetSmallletter();
		}
	}

	static string GenerateWord(enCharChoice CharChoice, short length = 4)
	{
		string Word = "";
		for (int i = 0; i < length; i++)
		{
			Word += GetRandomCharacter(CharChoice);
		}
		return Word;
	}

	static string GenerateKey(enCharChoice CharChoice, short KeyLength = 4, short WordLength = 4)
	{
		string Key = "";
		for (int i = 0; i < KeyLength - 1; i++)
		{
			Key += GenerateWord(CharChoice, WordLength) + "-";
		}
		return Key += GenerateWord(CharChoice, WordLength);
	}

	static void GenerateKeys(int KeysNumber, enCharChoice CharChoice, short KeyLength = 4, short WordLength = 4)
	{
		for (int i = 1; i <= KeysNumber; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharChoice, KeyLength, WordLength) << endl;
		}
	}


	static void Swap(int& a, int& b)
	{
		int vSwap;
		vSwap = a;
		a = b;
		b = vSwap;
	}

	static void Swap(double& a, double& b)
	{
		double vSwap;
		vSwap = a;
		a = b;
		b = vSwap;
	}

	static void Swap(string& S1, string& S2)
	{
		string vSwap;
		vSwap = S1;
		S1 = S2;
		S2 = vSwap;
	}

	static void ShuffleArray(int arr[5], int x)
	{
		for (int i = 0; i < x; i++)
		{
			int FirstRand = RandomNumber(0, x - 1);
			int SecondRand = RandomNumber(0, x - 1);
			swap(arr[FirstRand], arr[SecondRand]);
		}
	}

	static void ShuffleArray(string arr[5], int x)
	{
		for (int i = 0; i < x; i++)
		{
			int FirstRand = RandomNumber(0, x - 1);
			int SecondRand = RandomNumber(0, x - 1);
			swap(arr[FirstRand], arr[SecondRand]);
		}
	}

	static void FillArrayWithRandomNumber(int arr[100], short arrLenght, int From = 0, int To = INT_MAX)
	{
		for (short i = 0; i < arrLenght; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], short arrLength, enCharChoice Charchoice, short WordLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(Charchoice, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], short arrLength, enCharChoice Charchoice, short WordLength = 4)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(Charchoice, 4, WordLength);
		}
	}


	static string Tabs(int TabsNumber)
	{
		string TabsString = "";
		for (int i = 0; i < TabsNumber; i++)
		{
			TabsString += "\t";
		}
		return TabsString;
	}


	static string EncryptText(string TextToEncrypt, short EncryptionKey)
	{
		for (int i = 0; i < TextToEncrypt.length(); i++)
		{
			TextToEncrypt[i] = char(TextToEncrypt[i] + 2);
		}
		return TextToEncrypt;
	}

	static string DecryptionText(string TextToDecrypt, short DecryptionKey)
	{
		for (int i = 0; i < TextToDecrypt.length(); i++)
		{
			TextToDecrypt[i] = char(TextToDecrypt[i] - 2);
		}
		return TextToDecrypt;
	}


	static string ConvertNumberToText(int Number)
	{

		if (Number >= 0 && Number <= 19)
		{
			string numbers[20] = {
					"", "one", "two", "three", "four", "five",
					"six", "seven", "eight", "nine", "ten",
					"eleven", "twelve", "thirteen", "fourteen", "fifteen",
					"sixteen", "seventeen", "eighteen", "nineteen"
			};
			return numbers[Number];
		}

		if (Number >= 20 && Number <= 99)
		{
			string tens[10] = {
				"", "", "twenty", "thirty", "forty", "fifty",
				"sixty", "seventy", "eighty", "ninety"
			};
			return tens[Number / 10] + " " + ConvertNumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + ConvertNumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return ConvertNumberToText(Number / 100) + " Hundreds " + ConvertNumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + ConvertNumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999'999)
		{
			return ConvertNumberToText(Number / 1000) + " Thousands " + ConvertNumberToText(Number % 1000);
		}

		if (Number >= 1'000'000 && Number <= 1'999'999)
		{
			return "One Million " + ConvertNumberToText(Number % 1'000'000);
		}

		if (Number >= 2'000'000 && Number <= 999'999'999)
		{
			return ConvertNumberToText(Number / 1'000'000) + " Millions " + ConvertNumberToText(Number % 1'000'000);
		}

		if (Number >= 1'000'000'000 && Number <= 1'999'999'999)
		{
			return "One Billion " + ConvertNumberToText(Number % 1'000'000'000);
		}

		if (Number >= 2'000'000'000 && Number <= 999'999'999'999)
		{
			return ConvertNumberToText(Number / 1'000'000'000) + " Billions " + ConvertNumberToText(Number % 1'000'000'000);
		}

		if (Number >= 1'000'000'000'000 && Number <= 1'999'999'999'999)
		{
			return "One Trillion " + ConvertNumberToText(Number % 1'000'000'000'000);
		}

		if (Number >= 2'000'000'000'000 && Number <= 999'999'999'999'999)
		{
			return ConvertNumberToText(Number / 1'000'000'000'000) + " Trillions " + ConvertNumberToText(Number % 1'000'000'000'000);
		}
	}
};