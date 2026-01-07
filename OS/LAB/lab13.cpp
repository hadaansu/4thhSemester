#include <iostream>
using namespace std;

int main() {
    int n, f, page[50], frame[10], i, j, k, avail, count = 0;

    cout << "Enter the number of pages: ";
    cin >> n;

    cout << "Enter the page reference string:\n";
    for (i = 0; i < n; i++)
        cin >> page[i];

    cout << "Enter the number of frames: ";
    cin >> f;

    for (i = 0; i < f; i++)
        frame[i] = -1;   // initialize empty frames

    j = 0; // pointer to next frame to replace

    cout << "\nPage\tFrames\tPage Fault\n";
    for (i = 0; i < n; i++) {
        avail = 0;
        // check if page is already in a frame
        for (k = 0; k < f; k++) {
            if (frame[k] == page[i]) {
                avail = 1;
                break;
            }
        }
        if (avail == 0) {  // page fault
            frame[j] = page[i];
            j = (j + 1) % f;  // FIFO: replace in circular order
            count++;
            cout << page[i] << "\t";
            for (k = 0; k < f; k++) {
                if (frame[k] != -1)
                    cout << frame[k] << " ";
                else
                    cout << "- ";
            }
            cout << "\tYes\n";
        } else {
            cout << page[i] << "\t";
            for (k = 0; k < f; k++) {
                if (frame[k] != -1)
                    cout << frame[k] << " ";
                else
                    cout << "- ";
            }
            cout << "\tNo\n";
        }
    }

    cout << "\nTotal Page Faults = " << count << endl;

    return 0;
}
