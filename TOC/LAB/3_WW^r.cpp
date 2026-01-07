// Lab 5.3: PDA for L = {WW^R | W ∈ (a+b)*}. Test with abba.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool pda(string &input)
{
	if (input.length() % 2 != 0)
		return false;

	char state = 'A';
	stack<char> s;
	s.push('z');

	for (int i = 0; i < input.length() / 2; i++)
	{
		switch (state)
		{
		case 'A':
			if (input[i] == 'a' || input[i] == 'b')
			{
				s.push(input[i]);
				state = 'A';
			}
			else
				return false;
			break;
		}
	}

	for (int i = input.length() / 2; i < input.length(); i++)
	{
		switch (state)
		{
		case 'A':
			if ((input[i] == 'a' && s.top() == 'a') ||
				(input[i] == 'b' && s.top() == 'b'))
			{
				s.pop();
				state = 'B';
			}
			else
				return false;
			break;

		case 'B':
			if ((input[i] == 'a' && s.top() == 'a') ||
				(input[i] == 'b' && s.top() == 'b'))
				s.pop();
			else
				return false;
			break;
		}
	}

	if (state == 'B' && s.top() == 'z')
		state = 'C';

	return (state == 'C' && s.top() == 'z');
}

int main()
{
	string input;
	cout << "Enter input : ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != 'a' && input[i] != 'b')
		{
			cout << "Invalid input. The alphabet is {a,b}.";
			return 0;
		}
	}

	if (pda(input))
		cout << "PDA accepts the string : " << input;
	else
		cout << "PDA rejects the string : " << input;

	return 0;
}
