#include <iostream>
using namespace std;

int main() {
    int n, f, page[50], frame[10], count[10];
    int i, j, k, flag1, flag2, pos, min, faults = 0;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string:\n";
    for (i = 0; i < n; i++)
        cin >> page[i];

    cout << "Enter number of frames: ";
    cin >> f;

    for (i = 0; i < f; i++) {
        frame[i] = -1;
        count[i] = 0;
    }

    cout << "\nPage\tFrames\tPage Fault\n";
    for (i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        // Check if page already in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                flag1 = flag2 = 1;
                count[j] = i + 1; // update recent use
                break;
            }
        }

        if (flag1 == 0) {
            // Check for empty frame
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    faults++;
                    frame[j] = page[i];
                    count[j] = i + 1;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            // Find least recently used page
            min = count[0];
            pos = 0;
            for (j = 1; j < f; j++) {
                if (count[j] < min) {
                    min = count[j];
                    pos = j;
                }
            }
            faults++;
            frame[pos] = page[i];
            count[pos] = i + 1;
        }

        // Print status
        cout << page[i] << "\t";
        for (k = 0; k < f; k++) {
            if (frame[k] != -1)
                cout << frame[k] << " ";
            else
                cout << "- ";
        }
        if (flag1 == 0) cout << "\tYes\n";
        else cout << "\tNo\n";
    }

    cout << "\nTotal Page Faults = " << faults << endl;

    return 0;
}
