#include <iostream>
using namespace std;

void MFT() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    cout << "\n--- Multiprogramming with Fixed Tasks (MFT) ---\n";
    cout << "Enter the total memory size: ";
    cin >> ms;
    cout << "Enter the block size: ";
    cin >> bs;

    nob = ms / bs;   // number of blocks
    ef = ms - nob * bs; // external fragmentation

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter memory required for each process:\n";
    for (int i = 0; i < n; i++)
        cin >> mp[i];

    cout << "\nNo. of Blocks available in memory: " << nob << endl;
    int p = 0;
    for (int i = 0; i < n && p < nob; i++) {
        if (mp[i] > bs)
            cout << "Process " << i + 1 << " of size " << mp[i] 
                 << " cannot be allocated \n";
        else {
            cout << "Process " << i + 1 << " of size " << mp[i] 
                 << " is allocated in Block " << p + 1 << endl;
            tif += bs - mp[i];
            p++;
        }
    }

    cout << "\nTotal Internal Fragmentation: " << tif;
    cout << "\nTotal External Fragmentation: " << ef << endl;
}

void MVT() {
    int ms, n, mp[10], i, temp, flag = 0;
    cout << "\n--- Multiprogramming with Variable Tasks ---\n";
    cout << "Enter the total memory size: ";
    cin >> ms;

    temp = ms; // available memory
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter memory required for each process:\n";
    for (i = 0; i < n; i++)
        cin >> mp[i];

    for (i = 0; i < n; i++) {
        if (mp[i] <= temp) {
            cout << "Process " << i + 1 << " of size " << mp[i] 
                 << " is allocated\n";
            temp -= mp[i];
        } else {
            cout << "Process " << i + 1 << " of size " << mp[i] 
                 << " cannot be allocated \n";
            flag = 1;
        }
    }

    cout << "\nTotal memory allocated = " << ms - temp;
    cout << "\nTotal External Fragmentation = " << temp << endl;
}

int main() {
    int choice;
    do {
        cout << "\n====== Memory Management Simulation ======";
        cout << "\n1. MFT (Fixed Partitioning)";
        cout << "\n2. MVT (Variable Partitioning)";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: MFT(); break;
            case 2: MVT(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 3);

    return 0;
}
