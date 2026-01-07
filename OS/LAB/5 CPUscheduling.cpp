#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;        // process ID
    int bt;         // burst time
    int at;         // arrival time
    int priority;   // priority
    int wt;         // waiting time
    int tat;        // turnaround time
};

// Function to calculate TAT and WT
void calculateTimes(Process p[], int n) {
    int totalWT = 0, totalTAT = 0;
    cout << "\nPID\tBT\tAT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
        cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].at 
             << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
    }
    cout << "Average Waiting Time = " << (float)totalWT / n << endl;
    cout << "Average Turnaround Time = " << (float)totalTAT / n << endl;
}

// FCFS Scheduling
void fcfs(Process p[], int n) {
    cout << "\n--- FCFS Scheduling ---\n";
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].wt = currentTime - p[i].at;
        currentTime += p[i].bt;
    }
    calculateTimes(p, n);
}

// SJF Scheduling (non-preemptive)
void sjf(Process p[], int n) {
    cout << "\n--- SJF Scheduling ---\n";
    // Sort by burst time (if equal, by arrival time)
    sort(p, p + n, [](Process a, Process b) {
        if (a.bt == b.bt) return a.at < b.at;
        return a.bt < b.bt;
    });

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].wt = currentTime - p[i].at;
        currentTime += p[i].bt;
    }
    calculateTimes(p, n);
}

// Priority Scheduling (non-preemptive)
void priorityScheduling(Process p[], int n) {
    cout << "\n--- Priority Scheduling ---\n";
    // Sort by priority (lower value = higher priority)
    sort(p, p + n, [](Process a, Process b) {
        if (a.priority == b.priority) return a.at < b.at;
        return a.priority < b.priority;
    });

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].wt = currentTime - p[i].at;
        currentTime += p[i].bt;
    }
    calculateTimes(p, n);
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[20];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Process " << i + 1 << ":\n";
        p[i].pid = i + 1;
        cout << "Burst Time: ";
        cin >> p[i].bt;
        cout << "Arrival Time: ";
        cin >> p[i].at;
        cout << "Priority: ";
        cin >> p[i].priority;
    }

    fcfs(p, n);
    sjf(p, n);
    priorityScheduling(p, n);

    return 0;
}
