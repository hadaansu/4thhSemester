// Lab 1.3: WAP to contruct DFA that accepts {10,01,001,110}
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input;
	char state = 'A';
	cout << "Enter input : ";
	cin >> input;
	for (int i = 0; i < input.length(); i++)
		if (input[i] != '0' && input[i] != '1')
		{
			cout << "Invalid input. The alphabet is {0,1}.";
			return 0;
		}
	for (int i = 0; i < input.length(); i++)
	{
		switch (state)
		{
		case 'A':
			state = (input[i] == '1') ? 'B' : 'D';
			break;
		case 'B':
			state = (input[i] == '0') ? 'C' : 'F';
			break;
		case 'D':
			state = (input[i] == '1') ? 'C' : 'E';
			break;
		case 'E':
			state = (input[i] == '1') ? 'C' : 'X';
			break;
		case 'F':
			state = (input[i] == '0') ? 'C' : 'X';
			break;
		case 'C':
		case 'X':
			state = 'X';
			break;
		}
	}
	if (state == 'C')
		cout << "DFA accepts the string : " << input;
	else
		cout << "DFA rejects the string : " << input;
	return 0;
}