// Lab 3.1: WAP to contruct Moore machine that gives output ababa
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input, output;
	char state = 'A';
	cout << "Enter input : ";
	cin >> input;
	for (int i = 0; i < input.length(); i++)
		if (input[i] != '0' && input[i] != '1')
		{
			cout << "Invalid input. The alphabet is {0,1}.";
			return 0;
		}
	output += "a";
	for (int i = 0; i < input.length(); i++)
	{
		switch (state)
		{
		case 'A':
			state = (input[i] == '1') ? 'A' : 'B';
			break;
		case 'B':
			state = (input[i] == '1') ? 'B' : 'C';
			break;
		case 'C':
			state = (input[i] == '1') ? 'C' : 'D';
			break;
		case 'D':
			state = (input[i] == '1') ? 'D' : 'E';
			break;
		case 'E':
			break;
		}
		switch (state)
		{
		case 'A':
			output += "a";
			break;
		case 'B':
			output += "b";
			break;
		case 'C':
			output += "a";
			break;
		case 'D':
			output += "b";
			break;
		case 'E':
			output += "a";
			break;
		}
	}
	if (output == "ababa")
		cout << "Moore Machine with input " << input << " gives the output : ababa";
	else
		cout << "Moore Machine with input " << input << " doesn't give the output : ababa";
	return 0;
}