/*
Lab 4.3: WAP to find leftmost derivation of given grammar
Grammar:
    S -> S*S | S+S | -S | (S) | id
String:
    -(id*id)+id
*/

#include <iostream>
#include <string>
using namespace std;

void replaceLeftmostS(string &expr, const string &replacement)
{
    int pos = expr.find('S'); // leftmost occurrence
    if (pos != string::npos)
        expr.replace(pos, 1, replacement);
}

void leftmostDerivation(const string productions[], int count, const string &start)
{
    const int MAX_STEPS = 50;
    string steps[MAX_STEPS];

    string expr = start;
    steps[0] = expr;

    for (int i = 0; i < count; i++)
    {
        replaceLeftmostS(expr, productions[i]);
        steps[i + 1] = expr;
    }

    cout << endl
         << "Leftmost derivation:";
    for (int i = 0; i <= count; i++)
        cout << endl
             << i + 1 << ": " << steps[i];
}

int main()
{
    string productions[] = {
        "-S",
        "S+S",
        "(S)",
        "S*S",
        "id",
        "id",
        "id"};

    int stepCount = sizeof(productions) / sizeof(productions[0]);
    string startSymbol = "S";

    cout << "Production :" << endl;
    cout << "S -> S*S | S+S | -S | (S) | id" << endl;

    leftmostDerivation(productions, stepCount, startSymbol);

    return 0;
}
