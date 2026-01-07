#include <iostream>
using namespace std;

int main() {
    int ms, ps, nop, np, nf, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];

    cout << "Enter the memory size: ";
    cin >> ms;
    cout << "Enter the page size: ";
    cin >> ps;

    nf = ms / ps; // number of frames
    cout << "Number of frames in memory: " << nf << endl;

    cout << "Enter the number of processes: ";
    cin >> nop;

    rempages = nf; // remaining free frames

    for (i = 0; i < nop; i++) {
        cout << "\nEnter number of pages required for process " << i + 1 << ": ";
        cin >> np;
        if (np > rempages) {
            cout << "Memory is Full, cannot allocate process " << i + 1 << ".\n";
            continue;
        }
        s[i] = np;
        rempages -= np;
        cout << "Enter frame numbers for process " << i + 1 << " pages:\n";
        for (j = 0; j < np; j++)
            cin >> fno[i][j];
    }

    cout << "\n--- Paging Simulation ---\n";
    cout << "Process\tPage Table (Page -> Frame)\n";
    for (i = 0; i < nop; i++) {
        cout << "P" << i + 1 << "\t";
        for (j = 0; j < s[i]; j++)
            cout << j << "->" << fno[i][j] << "  ";
        cout << endl;
    }

    // Logical to Physical Address Translation
    cout << "\nEnter Logical Address: ";
    cin >> x >> y >> offset;
    if (x > nop || y >= s[x - 1]) {
        cout << "Invalid Process or Page number\n";
        return 0;
    }

    pa = fno[x - 1][y] * ps + offset;
    cout << "Physical Address = " << pa << endl;

    return 0;
}
