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
        allocation[i] = -1; // initially not allocated

    // Best-Fit allocation
    for (int i = 0; i < np; i++) {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
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
