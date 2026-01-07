// Lab 3.3: WAP to convert DFA that accepts 1001 to regular expression
#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool dfa(string &input)
{
    int state = 0;
    for (int i = 0; i < input.length(); i++)
    {
        switch (state)
        {
        case 0:
            state = (input[i] == '1') ? 1 : 5;
            break;
        case 1:
            state = (input[i] == '0') ? 2 : 5;
            break;
        case 2:
            state = (input[i] == '0') ? 3 : 5;
            break;
        case 3:
            state = (input[i] == '1') ? 4 : 5;
            break;
        case 4:
            state = 5;
            break;
        case 5:
            return false;
        }
    }
    return (state == 4);
}

int main()
{
    string input;
    cout << "Enter input : ";
    cin >> input;
    for (int i = 0; i < input.length(); i++)
        if (input[i] != '0' && input[i] != '1')
        {
            cout << "Invalid input. The alphabet is {0,1}.";
            return 0;
        }
    if (dfa(input))
        cout << "DFA accepts the string : " << input << endl;
    else
        cout << "DFA rejects the string : " << input << endl;
    string regex_string = "^1001$";
    regex re(regex_string);
    if (regex_match(input, re))
        cout << "Regular expression matches the string: " << input << endl;
    else
        cout << "Regular expression does not match the string: " << input << endl;

    cout << "The equivalent regular expression is: " << regex_string << endl;
    return 0;
}