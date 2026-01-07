#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt, at, priority;
    int wt = 0, tat = 0, rt; // rt = remaining time
};

// Round Robin
void roundRobin(Process p[], int n, int quantum) {
    cout << "\n--- Round Robin Scheduling ---\n";
    queue<int> q;
    int time = 0, completed = 0;
    for (int i = 0; i < n; i++) p[i].rt = p[i].bt;

    q.push(0); // push first process
    bool inQueue[20] = {false};
    inQueue[0] = true;

    while (completed < n) {
        int i = q.front(); q.pop();
        inQueue[i] = false;

        if (p[i].rt > quantum) {
            time += quantum;
            p[i].rt -= quantum;
        } else {
            time += p[i].rt;
            p[i].wt = time - p[i].bt - p[i].at;
            p[i].tat = p[i].wt + p[i].bt;
            p[i].rt = 0;
            completed++;
        }

        for (int j = 0; j < n; j++) {
            if (p[j].at <= time && p[j].rt > 0 && !inQueue[j]) {
                q.push(j);
                inQueue[j] = true;
            }
        }
        if (p[i].rt > 0) { q.push(i); inQueue[i] = true; }
    }

    float avgWT = 0, avgTAT = 0;
    cout << "PID\tBT\tAT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].at
             << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
        avgWT += p[i].wt; avgTAT += p[i].tat;
    }
    cout << "Average WT = " << avgWT/n << "\n";
    cout << "Average TAT = " << avgTAT/n << "\n";
}

// Preemptive Priority Scheduling
void priorityPreemptive(Process p[], int n) {
    cout << "\n--- Preemptive Priority Scheduling ---\n";
    int time = 0, completed = 0;
    for (int i = 0; i < n; i++) p[i].rt = p[i].bt;

    while (completed < n) {
        int idx = -1, bestPriority = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].priority < bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }
        if (idx == -1) { time++; continue; }
        p[idx].rt--; time++;
        if (p[idx].rt == 0) {
            completed++;
            p[idx].tat = time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }

    float avgWT = 0, avgTAT = 0;
    cout << "PID\tBT\tAT\tPr\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].at
             << "\t" << p[i].priority << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
        avgWT += p[i].wt; avgTAT += p[i].tat;
    }
    cout << "Average WT = " << avgWT/n << "\n";
    cout << "Average TAT = " << avgTAT/n << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[20];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Process " << i+1 << ":\n";
        p[i].pid = i+1;
        cout << "Burst Time: "; cin >> p[i].bt;
        cout << "Arrival Time: "; cin >> p[i].at;
        cout << "Priority: "; cin >> p[i].priority;
    }

    int quantum;
    cout << "\nEnter Time Quantum for Round Robin: ";
    cin >> quantum;

    roundRobin(p, n, quantum);
    priorityPreemptive(p, n);

    return 0;
}
