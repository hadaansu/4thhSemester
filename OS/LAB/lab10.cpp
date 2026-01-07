#include <iostream>
using namespace std;

int main() {
    int nb, np;
    cout << "Enter number of memory blocks: ";
    cin >> nb;
    int blockSize[20];
    cout << "Enter size of each block:\n";
    for (int i = 0; i < nb; i++)
        cin >> blockSize[i];

    cout << "Enter number of processes: ";
    cin >> np;
    int processSize[20];
    cout << "Enter size of each process:\n";
    for (int i = 0; i < np; i++)
        cin >> processSize[i];

    int allocation[20];
    for (int i = 0; i < np; i++)
        allocation[i] = -1;  // -1 means not allocated

    // First-Fit allocation
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];  // reduce free space
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < np; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    return 0;
}
