#include "Header.h"

string incrypted;
string letters = "abcdefghijklmnopqrstuvwxyz";

int main()
{
	for (;;)
	{
		string temp;
		string phrase;
		char choice;

		cout << "Enter the phrase : ";
		cin >> temp;
		getline(cin, phrase);

		phrase = temp + phrase;

		cout << "\n[1] Incryption\n[2] Decription\n[3] Decryption whit out key\n\nChoice : ";
		cin >> choice;

		cout << "\n";

		switch (choice)
		{
		case '1':
			incryption(phrase);
			cout << "Incription : " << incrypted << "\n";
			incrypted = "";
			break;
		case '2':
			decryption(phrase);
			cout << "Decription : " << incrypted << "\n";
			incrypted = "";
			break;
		case '3':
			decritionWithOutKey(phrase);
			break;
		}
	}
}