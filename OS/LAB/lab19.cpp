#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void printTable(const vector<int>& order, int headStart) {
    int total = 0;
    int head = headStart;
    cout << "RequestId\tPosition\tMovement\n";
    for (int r : order) {
        int move = abs(head - r);
        total += move;
        head = r;
        cout << r << "\t\t" << head << "\t\t" << move << "\n";
    }
    double avg = (double)total / order.size();
    cout << "Total Head Movement = " << total << "\n";
    cout << "Average Head Movement = " << avg << "\n\n";
}

void FCFS(vector<int> req, int head) {
    cout << "--- FCFS Disk Scheduling ---\n";
    printTable(req, head);
}

void SCAN(vector<int> req, int head, int diskSize) {
    cout << "--- SCAN Disk Scheduling ---\n";
    sort(req.begin(), req.end());
    vector<int> order;
    auto it = lower_bound(req.begin(), req.end(), head);

    // Move right
    for (auto i = it; i != req.end(); ++i) order.push_back(*i);
    // Go to end if needed
    if (!order.empty() && order.back() != diskSize - 1) order.push_back(diskSize - 1);
    // Move left
    for (auto i = it; i != req.begin();) {
        --i;
        order.push_back(*i);
    }

    printTable(order, head);
}

void LOOK(vector<int> req, int head) {
    cout << "--- LOOK Disk Scheduling ---\n";
    sort(req.begin(), req.end());
    vector<int> order;
    auto it = lower_bound(req.begin(), req.end(), head);

    // Move right
    for (auto i = it; i != req.end(); ++i) order.push_back(*i);
    // Move left
    for (auto i = it; i != req.begin();) {
        --i;
        order.push_back(*i);
    }

    printTable(order, head);
}

int main() {
    int n, head, diskSize;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter request sequence: ";
    for (int i = 0; i < n; ++i) cin >> requests[i];

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter disk size: ";
    cin >> diskSize;

    cout << "\nDisk Scheduling Simulation\n\n";

    FCFS(requests, head);
    SCAN(requests, head, diskSize);
    LOOK(requests, head);

    return 0;
}
