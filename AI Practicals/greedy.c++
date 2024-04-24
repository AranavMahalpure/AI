#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void printJobScheduling(vector<Job> jobs) {
    int n = jobs.size();
    vector<int> result(n);
    sort(jobs.begin(), jobs.end(), compare);

    vector<bool> slot(n + 1, false);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j > 0; j--) {
            if (slot[j] == false) {
                result[j - 1] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i + 1] == true) {
            totalProfit += jobs[result[i]].profit;
        }
    }

    cout << "The optimal profit is " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = { {4, 20}, {1, 10}, {1, 40}, {1, 30} };
    printJobScheduling(jobs);

    return 0;
}