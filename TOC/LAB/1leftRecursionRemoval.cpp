/*Lab 4.1: WAP to remove the left recursion of given production
	E->E+T|T
	T->T*F|F
	F->(E)|id
*/
#include <iostream>
#include <cstring>
using namespace std;

void removeLeftRecursion(char nonTerminal, char production[])
{
	char alpha[10][50];
	char beta[10][50];
	int alphaCount = 0, betaCount = 0;

	char *token = strtok(production, "|");
	while (token != NULL)
	{
		if (token[0] == nonTerminal)
		{
			strcpy(alpha[alphaCount], token + 1);
			alphaCount++;
		}
		else
		{
			strcpy(beta[betaCount], token);
			betaCount++;
		}

		token = strtok(NULL, "|");
	}

	if (alphaCount > 0)
	{

		for (int i = 0; i < betaCount; i++)
			cout << nonTerminal << " -> " << beta[i] << nonTerminal << endl;

		cout << nonTerminal << "' -> ";
		for (int i = 0; i < alphaCount; i++)
		{
			cout << alpha[i] << nonTerminal << "'";
			if (i < alphaCount - 1)
				cout << " | ";
		}
		cout << " | EPS" << endl;
	}
	else
	{
		cout << nonTerminal << " -> ";
		char *again = strtok(production, "|");
		while (again != NULL)
		{
			cout << again;
			again = strtok(NULL, "|");
			if (again)
				cout << " | ";
		}
		cout << endl;
	}
}

int main()
{
	cout << "Original production :" << endl;
	cout << "E -> E+T | T" << endl;
	cout << "T -> T*F | F" << endl;
	cout << "F -> (E) | id" << endl;
	cout << endl
		 << "Production after removing left recursion :" << endl;
	char eProd[] = "E+T|T";
	char tProd[] = "T*F|F";
	removeLeftRecursion('E', eProd);
	removeLeftRecursion('T', tProd);
	cout << "F -> (E) | id";
	return 0;
}
