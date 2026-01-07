#include <iostream>
using namespace std;

int predict(int pages[], int n, int frame[], int f, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < f; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) // page not used again
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int n, f;
    cout << "Enter number of pages: ";
    cin >> n;
    int pages[50];
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    int frame[10];
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    int faults = 0;
    cout << "\nPage\tFrames\tPage Fault\n";

    for (int i = 0; i < n; i++) {
        bool hit = false;

        // Check if page is already in frame
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
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

            // If no empty frame, find optimal replacement
            if (replace == -1) {
                replace = predict(pages, n, frame, f, i + 1);
            }

            frame[replace] = pages[i];
            faults++;
        }

        // Print current frame status
        cout << pages[i] << "\t";
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                cout << frame[j] << " ";
            else
                cout << "- ";
        }
        if (!hit) cout << "\tYes\n";
        else cout << "\tNo\n";
    }

    cout << "\nTotal Page Faults = " << faults << endl;
    return 0;
}
