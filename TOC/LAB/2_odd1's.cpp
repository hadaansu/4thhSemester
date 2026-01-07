// Lab 2.2: WAP to contruct NFA that accepts odd number of 1's
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
			if (input[i] == '1')
				state = 'B';
			break;
		case 'B':
			if (input[i] == '1')
				state = 'A';
			break;
		}
	}
	if (state == 'B')
		cout << "NFA accepts the string : " << input;
	else
		cout << "NFA rejects the string : " << input;
	return 0;
}