#include <iostream>
using namespace std;

int main() {
    int n, f;
    cout << "Enter number of pages: ";
    cin >> n;
    int page[50];
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++)
        cin >> page[i];

    cout << "Enter number of frames: ";
    cin >> f;
    
    int frame[10], freq[10], age[10];
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        freq[i] = 0;
        age[i] = 0;
    }

    int faults = 0;
    cout << "\nPage\tFrames\tPage Fault\n";

    for (int i = 0; i < n; i++) {
        bool hit = false;

        // Check if page already in frame
        for (int j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                freq[j]++;
                hit = true;
                break;
            }
        }

        if (!hit) {
            int replace = -1;

            // Check for empty frame
            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    replace = j;
                    break;
                }
            }

            // If no empty frame, find LFU
            if (replace == -1) {
                int minFreq = freq[0];
                replace = 0;
                for (int j = 1; j < f; j++) {
                    if (freq[j] < minFreq || (freq[j] == minFreq && age[j] < age[replace])) {
                        minFreq = freq[j];
                        replace = j;
                    }
                }
            }

            frame[replace] = page[i];
            freq[replace] = 1;
            age[replace] = i;  // timestamp for tie-breaker
            faults++;
        }

        // Print current frames
        cout << page[i] << "\t";
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                cout << frame[j] << " ";
            else
                cout << "- ";
        }
        if (!hit) cout << "\tYes\n";
        else cout << "\tNo\n";

        // Increment age for all frames (optional, handled by i timestamp)
    }

    cout << "\nTotal Page Faults = " << faults << endl;
    return 0;
}
