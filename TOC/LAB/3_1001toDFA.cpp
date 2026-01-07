#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
using namespace std;

map<pair<int, char>, set<int>> nfa;
set<int> acceptingNFA;

bool isAccepting(const set<int> &s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it)
		if (acceptingNFA.count(*it))
			return true;
	return false;
}

void printSet(const set<int> &s)
{
	cout << "{";
	for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		if (it != s.begin())
			cout << ",";
		cout << "q" << *it;
	}
	cout << "}";
}

int main()
{
	set<int> t1;
	t1.insert(1);
	nfa[make_pair(0, '1')] = t1;
	set<int> t2;
	t2.insert(2);
	nfa[make_pair(1, '0')] = t2;
	set<int> t3;
	t3.insert(3);
	nfa[make_pair(2, '0')] = t3;
	set<int> t4;
	t4.insert(4);
	nfa[make_pair(3, '1')] = t4;

	acceptingNFA.insert(4);

	map<set<int>, int> dfaStateID;
	vector<set<int>> dfaStates;
	map<pair<int, char>, int> dfaTrans;
	vector<bool> dfaAccepting;
	queue<set<int>> q;

	set<int> start;
	start.insert(0);
	dfaStateID[start] = 0;
	dfaStates.push_back(start);
	dfaAccepting.push_back(isAccepting(start));
	q.push(start);

	int id = 1;

	while (!q.empty())
	{
		set<int> curr = q.front();
		q.pop();
		int currID = dfaStateID[curr];

		for (int i = 0; i < 2; ++i)
		{
			char c = (i == 0) ? '0' : '1';
			set<int> next;

			for (set<int>::iterator it = curr.begin(); it != curr.end(); ++it)
			{
				pair<int, char> key = make_pair(*it, c);
				if (nfa.count(key))
				{
					set<int> targets = nfa[key];
					next.insert(targets.begin(), targets.end());
				}
			}

			if (!next.empty())
			{
				if (dfaStateID.find(next) == dfaStateID.end())
				{
					dfaStateID[next] = id++;
					dfaStates.push_back(next);
					dfaAccepting.push_back(isAccepting(next));
					q.push(next);
				}
				dfaTrans[make_pair(currID, c)] = dfaStateID[next];
			}
		}
	}

	cout << "DFA States :" << endl;
	for (int i = 0; i < dfaStates.size(); i++)
	{
		cout << "D" << i << " = ";
		printSet(dfaStates[i]);
		if (dfaAccepting[i])
			cout << " [Accepting]";
		cout << endl;
	}

	cout << endl
		 << "DFA Transitions :" << endl;
	for (map<pair<int, char>, int>::iterator it = dfaTrans.begin(); it != dfaTrans.end(); ++it)
	{
		cout << "D" << it->first.first << " --" << it->first.second << "--> D" << it->second << endl;
	}

	string input;
	cout << endl
		 << "Enter input : ";
	cin >> input;
	for (int i = 0; i < input.length(); i++)
		if (input[i] != '0' && input[i] != '1')
		{
			cout << "Invalid input. The alphabet is {0,1}.";
			return 0;
		}
	int curr = 0;
	for (int i = 0; i < input.length(); i++)
	{
		pair<int, char> key = make_pair(curr, input[i]);
		if (dfaTrans.count(key))
			curr = dfaTrans[key];
		else
		{
			curr = -1;
			break;
		}
	}

	if (curr != -1 && dfaAccepting[curr])
		cout << "DFA accepts the string : " << input;
	else
		cout << "DFA rejects the string : " << input;

	return 0;
}
