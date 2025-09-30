/******************************************************************************



*******************************************************************************/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

string response, ed, text;
int key;

void encode(const string plain);
void decode(const string plain);


int main()
{
	cout << "Hello, would you like to encode or decode some text? (Yes/No)\n";
	cin >> response;


	if (response == "Yes")
	{
		cout << "\nAlright, would you like to encode or decode? (E/D)\n";
		cin >> ed;

		if (ed == "E")
		{
			cout << "Ok, what would you like to encode?\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, text);
			encode(text);
		}

		else if (ed == "D")
		{
			cout << "Ok, what would you like to decode?\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, text);
			decode(text);
		}

		else
		{
			cout << "Error: Response not recognized. Please try again.\n\n";
			main();
		}
	}

	else if (response == "No")
	{
		cout << "Ok, goodbye!";
		return 0;
	}

	else
	{
		cout << "Error: Response not recognized. Please try again.\n";
		main();
	}

	return 0;
}


void encode(const string plain)
{
	string result = "";
	string restart;

	cout << "\nWhat should the key be? Please enter a whole number: \n";
	cin >> key;


	for (int i = 0; i < plain.length(); i++)
	{
		if (isupper(plain[i]))
		{
			result += char(int(plain[i] + key - 65) % 26 + 65);
		}

		else if (islower(plain[i]))
		{
			result += char(int(plain[i] + key - 97) % 26 + 97);
		}

		else if (plain[i] >= 48 && plain[i] <= 57)
		{
			// Reverse shift printable ASCII
			result += char(int(plain[i] + key - 48) % 10 + 48);
		}

		else
		{
			result += int(plain[i]);
		}

	}

	cout << "\nEncoded text: " << result << endl;


	cout << "\nWould you like encode/decode something else? (Yes/No)" << endl;
	cin >> restart;

	if (restart == "Yes")
	{
		main();
	}

	else if (restart == "No")
	{
		cout << "Ok, goodbye!";
		exit(0);
	}

	else
	{
		cout << "Error: Response not recognized. Ending session...\n";
		exit(0);
	}
}


void decode(const string plain)
{
	string result = "";
	string restart;

	cout << "\nWhat should the key be? Please enter a whole number: \n";
	cin >> key;

	for (int i = 0; i < plain.length(); i++)
	{
		if (isupper(plain[i]))
			result += char(int(plain[i] - 65 - key + 26) % 26 + 65);

		else if (islower(plain[i]))
			result += char(int(plain[i] - 97 - key + 26) % 26 + 97);

		else if (plain[i] >= 48 && plain[i] <= 57)
			result += char(int(plain[i] - 48 - key + 10) % 10 + 48);

		else
			result += plain[i];
	}

	cout << "\nDecoded text: " << result << endl;


	cout << "\nWould you like encode/decode something else? (Yes/No)" << endl;
	cin >> restart;

	if (restart == "Yes")
	{
		main();
	}

	else if (restart == "No")
	{
		cout << "Ok, goodbye!";
		exit(0);
	}

	else
	{
		cout << "Error: Response not recognized. Ending session...\n";
		exit(0);
	}
}


