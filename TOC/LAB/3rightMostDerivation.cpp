/*Lab 4.3: WAP to find right most derivation of given grammar
    S->S*S|S+S|-S|(S)|id
    string: -(id*id)+id
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void replaceRightmostS(string &expr, const string &replacement)
{
    int pos = expr.rfind('S');
    if (pos != string::npos)
        expr.replace(pos, 1, replacement);
}

void rightmostDerivation(const string productions[], int count, const string &start)
{
    const int MAX_STEPS = 50;
    string steps[MAX_STEPS];

    string expr = start;
    steps[0] = expr;

    for (int i = 0; i < count; i++)
    {
        replaceRightmostS(expr, productions[i]);
        steps[i + 1] = expr;
    }

    cout << endl
         << "Rightmost derivation :";
    for (int i = 0; i <= count; i++)
        cout << endl
             << i + 1 << ": " << steps[i];
}

int main()
{

    string productions[] = {
        "S+S",
        "id",
        "-S",
        "(S)",
        "S*S",
        "id",
        "id"};

    int stepCount = sizeof(productions) / sizeof(productions[0]);
    string startSymbol = "S";
    cout << "Production :" << endl;
    cout << "S -> S*S | S+S | -S | (S) | id" << endl;
    rightmostDerivation(productions, stepCount, startSymbol);

    return 0;
}
