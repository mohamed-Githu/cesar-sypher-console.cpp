#include "Header.h"

extern string incrypted;
extern string letters;

void incryption(string& phrase)
{
	int key = chiave();
	for (int x = 0; x < phrase.size(); x++)
	{
		for (int y = 0; y < letters.size(); y++)
		{
			if (phrase[x] == letters[y])
			{
				int index = (y + key) % letters.size();
				incrypted += letters[index];
				break;
			}
		}
	}
}

void decryption(string& phrase)
{
	int key = chiave();
	for (int x = 0; x < phrase.size(); x++)
	{
		for (int y = 0; y < letters.size(); y++)
		{
			if (phrase[x] == letters[y])
			{
				int index = (y - key) % letters.size();
				incrypted += letters[index];
				break;
			}
		}
	}
}

static void noKey(string& phrase, string& incrypted)
{
	static int key = letters.size();
	for (int x = 0; x < phrase.size(); x++)
	{
		bool found = false;
		for (int y = 0; y < letters.size(); y++)
		{
			if (phrase[x] == letters[y])
			{
				int index = (y - key) % letters.size();
				incrypted += letters[index];
				found = true;
			}
			if (found)
				break;
		}
	}
	key++;
}

void decritionWithOutKey(string& phrase)
{
	bool done = false;
	int times = letters.size() + 1;
	while (times > 0 && !done)
	{
		int count = 994;
		noKey(phrase, incrypted);
		ifstream file("words.txt");
		int index = 0;
		string temp;

		while (temp != incrypted && count > 0)
		{
			file >> temp;
			if (temp == incrypted)
			{
				done = true;
				break;
			}
			count--;
		}
		if (!done)
			incrypted = "";
		times--;
	}
	if (!done)
		cout << "Word not found";
	else
		cout << "The word is : " << incrypted;
}

static int chiave()
{
	int key;
	cout << "Enter the key : ";
	cin >> key;

	key = key % letters.size();

	cout << "\n-------------------\n\n";

	return key;
}