// Lab 3.2: WAP to contruct Mealy machine that gives output abbaa
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
	for (int i = 0; i < input.length(); i++)
	{
		switch (state)
		{
		case 'A':
			output += (input[i] == '0') ? 'a' : 'a';
			state = (input[i] == '0') ? 'B' : 'A';
			break;
		case 'B':
			output += (input[i] == '0') ? 'b' : 'a';
			state = (input[i] == '0') ? 'C' : 'A';
			break;
		case 'C':
			output += (input[i] == '0') ? 'b' : 'a';
			state = (input[i] == '0') ? 'D' : 'A';
			break;
		case 'D':
			output += (input[i] == '0') ? 'a' : 'a';
			state = (input[i] == '0') ? 'E' : 'A';
			break;
		case 'E':
			output += (input[i] == '0') ? 'a' : 'a';
			state = (input[i] == '0') ? 'F' : 'A';
			break;
		case 'F':
			break;
		}
	}
	if (output == "abbaa")
		cout << "Mealy Machine with input " << input << " gives the output : abbaa";
	else
		cout << "Mealy Machine with input " << input << " doesn't give the output : abbaa";
	return 0;
}