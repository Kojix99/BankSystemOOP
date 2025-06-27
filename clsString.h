#pragma once

#include <vector>
#include <iostream>

using namespace std;


class ClsStringOptions
{
public:
	virtual vector<string> SplitFunction(string S1, string Delimiter) = 0;
};


class clsString
{
public:
	enum enWhatToCount
	{
		SmallLetter = 0,
		UpperLeters = 1,
		AllLetters = 2
	};
private:

	string _Value;
	static char IsVowel(char c)
	{
		return c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'u';
	}
	static char InvertLetterCase(char c)
	{
		return (isupper(c) ? tolower(c) : toupper(c));
	}

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	// CountWords
	static short CountWords(string S1)
	{
		short Counter = 0;
		int pos;
		string sWrod;
		while ((pos = S1.find(" ")) != string::npos)
		{
			sWrod = S1.substr(0, pos);
			if (!sWrod.empty())
			{
				Counter++;
			}
			S1.erase(0, pos + 1);
		}
		if (!S1.empty())
		{
			Counter++;
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	//Print FirstLetter
	static string PrintFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		cout << "\nFirst letters of this string: \n";

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				cout << S1[i] << endl;
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	//UpperFirstLetterOfEachWord
	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	//UpperCaseAllLetterOfString
	static string UpperAllLetters(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void UpperAllLetters()
	{
		_Value = UpperAllLetters(_Value);
	}

	//LowerCaseAllLettersOfString
	static string LowerAllLetters(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void LowerAllLetters()
	{
		_Value = LowerAllLetters(_Value);
	}

	//InvertCharacterCase
	static string InvertletterCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertletterCase()
	{
		_Value = InvertletterCase(_Value);
	}

	//CountCapitalLetter
	static short CountCapitalLetter(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	//CountSmallLetter
	static short CountSmallLetter(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLetter()
	{
		return CountSmallLetter(_Value);
	}

	//CountLettersByEnum
	static short CountLettersByEnum(string S1, enWhatToCount WhatToCount)
	{
		if (WhatToCount == enWhatToCount::AllLetters)
		{
			return S1.length();
		}
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::SmallLetter && islower(S1[i]))
			{
				Counter++;
			}
			if (WhatToCount == enWhatToCount::UpperLeters && isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountLettersByEnum(enWhatToCount WhatToChount)
	{
		return CountLettersByEnum(_Value, WhatToChount);
	}

	//CountReadCharacter
	static short CountSpecificCharacter(string S1, char CharToCount)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] == CharToCount)
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSpecificCharacter(char CharToCount)
	{
		return CountSpecificCharacter(_Value, CharToCount);
	}

	//CountSpecificCharacterRequest
	static short CountSpecificCharacterRequest(string S1, char CharToCount, bool MatchCase)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == CharToCount)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(S1[i]) == tolower(CharToCount))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}
	short CountSpecificCharacterRequest(char CharToCount, bool MatchCase)
	{
		return CountSpecificCharacterRequest(_Value, CharToCount, MatchCase);
	}

	//CountVowel
	static short CountVowel(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountVowel()
	{
		return CountVowel(_Value);
	}

	//PrintVowel
	static void PrintVowel(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
			{
				cout << S1[i] << "     ";
			}
		}
	}
	void PrintVowel()
	{
		PrintVowel(_Value);
	}

	//PrintEachWordInString
	static void PrintEachWordInString(string S1)
	{
		string sWord;
		short pos;
		while ((pos = S1.find(' ')) != string::npos)
		{
			sWord = S1.substr(0, pos);
			if (!sWord.empty())
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + 1);
		}
		if (!S1.empty())
		{
			cout << S1 << endl;
		}
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	//SplitFunction
	static vector<string> SplitByDelimiter(string S1, string Delimiter)
	{
		vector<string> vString;
		short pos;
		string sWord;
		while ((pos = S1.find(Delimiter)) != string::npos)
		{
			sWord = S1.substr(0, pos);
			if (!sWord.empty())
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delimiter.length());
		}
		if (!S1.empty())
		{
			vString.push_back(S1);
		}
		return vString;
	}
	vector<string> SplitByDelimiter(string Delimiter = "#//#")
	{
		return SplitByDelimiter(_Value, Delimiter);
	}

	//Triming
	static string TrimLeft(string S1)
	{
		string RealS1 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}
	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}
	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}


	//JoiningVector
	static string JoinString(vector<string> vString, string Delimiter)
	{
		string JoinedString;
		for (short i = 0; i < vString.size(); i++)
		{
			JoinedString += vString[i] + Delimiter;
		}
		return JoinedString.substr(0, JoinedString.length() - Delimiter.length());
	}
	//JoiningArray
	static string JoinString(string sArr[100], short size, string Delimiter)
	{
		string S1;
		for (short i = 0; i < size; i++)
		{
			S1 += sArr[i] + Delimiter;
		}
		return S1.substr(0, S1.length() - Delimiter.length());
	}

	//Reverse word
	static string ReverseWord(string S1)
	{
		vector<string> vString = SplitByDelimiter(S1, " ");
		string S2 = "";
		for (short i = vString.size() - 1; i >= 0; i--)
		{
			S2 += vString[i] + " ";
		}

		return S2;
	}
	void ReverseWord()
	{
		_Value = ReverseWord(_Value);
	}


	//Change Word;
	static string ReplaceWord(string S1, string WordToReplace, string NewWord)
	{
		string S2;
		vector<string> vString = SplitByDelimiter(S1, " ");
		for (const string& TempString : vString)
		{
			if (TempString == WordToReplace)
				S2 += NewWord + " ";
			else
				S2 += TempString + " ";
		}
		return S2.substr(0, S2.length() - 1);
	}
	void ReplaceWord(string WordToReplace, string NewWord)
	{
		_Value = ReplaceWord(_Value, WordToReplace, NewWord);
	}


	//Change word By Request
	static string ChangeWordCheckMatchCase(string S1, string WordToReplace, string NewWord, bool MatchCase = true)
	{
		string S2 = "";
		vector<string> vString = SplitByDelimiter(S1, " ");
		for (short i = 0; i < vString.size(); i++)
		{
			if (vString[i] == WordToReplace)
				S2 += NewWord + " ";
			else if (LowerAllLetters(vString[i]) == LowerAllLetters(WordToReplace) && !MatchCase)
				S2 += NewWord + " ";
			else
				S2 += vString[i] + " ";
		}
		return S2.substr(0, S2.length() - 1);
	}
	void ChangeWordCheckMatchCase(string WordToReplace, string NewWord, bool MatchCase = true)
	{
		_Value = ChangeWordCheckMatchCase(_Value, WordToReplace, NewWord, MatchCase);
	}

	//Remove Punc
	static string RemovePunc(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2.push_back(S1[i]);
			}
		}
		return S2;
	}
	void RemovePunc()
	{
		_Value = RemovePunc(_Value);
	}
};