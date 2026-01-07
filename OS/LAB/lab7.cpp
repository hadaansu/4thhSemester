#include <iostream>
using namespace std;

int main() {
    int n, m; // n = number of processes, m = number of resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], avail[m];
    int need[n][m], finish[n] = {0}, safeSeq[n];

    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Maximum Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "\nEnter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0; // count for safe sequence
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) { // all resources can be allocated
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "\nSystem is not in a safe state (Deadlock possible).\n";
            return 0;
        }
    }

    cout << "\nSystem is in a safe state.\nSafe Sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] << " ";
    cout << endl;

    return 0;
}
