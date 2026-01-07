// Lab 5.2: WAP to design PDA that accepts L={WcW^r | W belongs to (0+1)*}. Also check for 11c11.
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool pda(string &input)
{
	char state = 'A';
	stack<char> s;
	s.push('z');
	for (int i = 0; i < input.length(); i++)
	{
		switch (state)
		{
		case 'A':
			if (input[i] == '0' && (s.top() == 'z' || s.top() == '0' || s.top() == '1'))
			{
				s.push('0');
				state = 'A';
			}
			else if (input[i] == '1' && (s.top() == 'z' || s.top() == '0' || s.top() == '1'))
			{
				s.push('1');
				state = 'A';
			}
			else if (tolower(input[i]) == 'c')
				state = 'B';
			else
				return false;
			break;
		case 'B':
			if (input[i] == '0' && s.top() == '0')
			{
				s.pop();
				state = 'B';
			}
			else if (input[i] == '1' && s.top() == '1')
			{
				s.pop();
				state = 'B';
			}
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
		if (input[i] != '0' && input[i] != '1' && input[i] != 'c' && input[i] != 'C')
		{
			cout << "Invalid input. The alphabet is {0,1}.";
			return 0;
		}
	if (pda(input))
		cout << "PDA accepts the string : " << input;
	else
		cout << "PDA rejects the string : " << input;
	return 0;
}
