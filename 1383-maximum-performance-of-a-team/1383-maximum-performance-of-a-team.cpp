class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1000000007;
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long speedSum = 0;
        long long maxPerformance = 0;
        for (auto &engineer : engineers) {
            int currEfficiency = engineer.first;
            int currSpeed = engineer.second;
            minHeap.push(currSpeed);
            speedSum += currSpeed;
            if (minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }
            long long performance = speedSum * currEfficiency;

            maxPerformance = max(maxPerformance, performance);
        }

        return maxPerformance % MOD;
    }
};