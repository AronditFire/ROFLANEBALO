#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	string Word = "";
	string NewWord = "";

	int index = 0;
	int FirstStarIndex = 0;
	int SecondStarIndex = 0;
	bool FirstStarIsFound = false;
	bool SecondStarIsFound = false;

	cout << "Введите строку с английскими маленькими буквами: ";
	getline(cin, Word);

	for (int i = 0; i < Word.length(); ++i)
	{
		if (Word[i] == '*' && !FirstStarIndex)
		{
			FirstStarIndex = i;
			FirstStarIsFound = true;
		}
		else if (Word[i] == '*' && FirstStarIndex)
		{
			SecondStarIndex = i;
			SecondStarIsFound = true;
		}
	}
	
	if (FirstStarIsFound && SecondStarIsFound)
	{
		for (int i = FirstStarIndex + 1; i < SecondStarIndex; ++i)
		{
			NewWord.push_back(Word[i]);
		}
		cout << "Строка с символами между *: " << NewWord << endl;
	}
	else if (FirstStarIsFound && !SecondStarIsFound)
	{
		for (int i = FirstStarIndex + 1; i < Word.length(); ++i)
		{
			NewWord.push_back(Word[i]);
		}
		cout << "Строка с символами после *: " << NewWord << endl;
	}
	else
	{
		cout << "В строке нет *. Ошибка!\n";
		return 1;
	}

	sort(NewWord.begin(), NewWord.end());

	cout << "Отсортированная строка: " << NewWord << endl;

	return 0;
}