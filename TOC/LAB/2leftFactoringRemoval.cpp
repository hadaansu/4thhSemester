/*Lab 4.2: WAP to remove the left factoring of given grammar
    E -> iEtsAs | iEs
    A -> a
*/
#include <iostream>
#include <cstring>

using namespace std;

void leftFactoring(char nonTerminal, char productions[][50], int count)
{

    string prefix = productions[0];

    for (int i = 1; i < count; i++)
    {
        int j = 0;
        while (j < prefix.size() && j < strlen(productions[i]) && prefix[j] == productions[i][j])
            j++;
        prefix = prefix.substr(0, j);
        if (prefix.empty())
            break;
    }

    if (prefix.empty())
    {

        cout << nonTerminal << " -> ";
        for (int i = 0; i < count; i++)
        {
            cout << productions[i];
            if (i != count - 1)
                cout << " | ";
        }
        cout << endl;
        return;
    }

    cout << nonTerminal << " -> " << prefix << nonTerminal << "'" << endl;
    cout << nonTerminal << "' -> ";

    for (int i = 0; i < count; i++)
    {
        const char *prod = productions[i];
        int prodLen = strlen(prod);
        if (prodLen > prefix.size())
            cout << (prod + prefix.size());
        else
            cout << "EPS";
        if (i != count - 1)
            cout << " | ";
    }
    cout << endl;
}

int main()
{
    cout << "Original grammar :" << endl;
    cout << "E -> iEtsAs | iEts" << endl;
    cout << "A -> a" << endl
         << endl;
    cout << "Grammar after removing left factoring :" << endl;
    char eProductions[2][50] = {"iEtsAs", "iEts"};
    leftFactoring('E', eProductions, 2);
    cout << "A -> a";
    return 0;
}
