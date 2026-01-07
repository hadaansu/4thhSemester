// Lab 6.4: WAP to design TM that accepts 2's complement of binary input.
#include <iostream>
#include <string>
using namespace std;
string tm(string input)
{
	char state = 'A';
	int head = 0;
	input.insert(input.begin(), 'B');
	input.push_back('B');

	while (true)
	{
		switch (state)
		{
		case 'A':
			if (input[head] == 'B' && head == 0)
				head++;
			else if (input[head] == '0' || input[head] == '1')
				head++;
			else if (input[head] == 'B' && head > 0)
			{
				state = 'B';
				head--;
			}
			else
				return "ERROR";
			break;

		case 'B':
			if (input[head] == '0')
				head--;
			else if (input[head] == '1')
			{
				state = 'C';
				head--;
			}
			else if (input[head] == 'B')
				state = 'D';
			else
				return "ERROR";
			break;

		case 'C':
			if (input[head] == '0')
			{
				input[head] = '1';
				head--;
			}
			else if (input[head] == '1')
			{
				input[head] = '0';
				head--;
			}
			else if (input[head] == 'B')
				state = 'D';
			else
				return "ERROR";
			break;

		case 'D':
			if (!input.empty() && input.front() == 'B')
				input.erase(input.begin());
			if (!input.empty() && input.back() == 'B')
				input.pop_back();
			return input;
		}
	}
}

int main()
{
	string input;
	cout << "Enter input: ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
		if (input[i] != '0' && input[i] != '1')
		{
			cout << "Invalid input. The alphabet is {0,1}.";
			return 0;
		}

	string result = tm(input);
	cout << "2's complement of " << input << " : " << result;
	return 0;
}