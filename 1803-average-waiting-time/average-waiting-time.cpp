class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int currTime = customers[0][0];
        double totalWaitTime = 0;

        for (vector<int> v : customers) {
            int arrival = v[0];
            int duration = v[1];

            if (arrival > currTime) {
                currTime = arrival;
            }

            int waitTime = currTime + duration - arrival;
            totalWaitTime += waitTime;
            currTime += duration;
        }
        return totalWaitTime / n;
    }
};