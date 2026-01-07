// Lab 5.4: WAP to design PDA that accepts L={a^2n b^n | n>=1}.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool pda(string &input)
{
	char state = 'A';
	stack<char> s;
	s.push('z');
	int aCount = 0;
	for (int i = 0; i < input.length(); i++)
	{

		switch (state)
		{
		case 'A':
			if (input[i] == 'a')
			{
				aCount++;
				if (s.top() == 'z'  && aCount % 2 != 0)
				{
					s.push('a');
					state = 'A';
				}
				else
					state = 'B';
			}
			else
				return false;
			break;
		case 'B':
			if (input[i] == 'a' && s.top() == 'a')
			{
				aCount++;
				s.push('a');
				state = 'A';
			}
			else if (input[i] == 'b' && s.top() == 'a')
			{
				s.pop();
				state = 'C';
			}
			else
				return false;
			break;
		case 'C':
			if (input[i] == 'b' && s.top() == 'a')
				s.pop();
			else
				return false;
			break;
		}
	}

	if (state == 'C' && s.top() == 'z')
		state = 'D';

	return (state == 'D' && s.top() == 'z');
}

int main()
{
	string input;
	cout << "Enter input : ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
		if (input[i] != 'a' && input[i] != 'b')
		{
			cout << "Invalid input. The alphabet is {a,b}.";
			return 0;
		}

	if (pda(input))
		cout << "PDA accepts the string : " << input;
	else
		cout << "PDA rejects the string : " << input;

	return 0;
}
