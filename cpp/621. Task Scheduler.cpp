class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        unordered_map<char, int> taskFreq;
        for (char task : tasks) {
            taskFreq[task]++;
        }

        // Find the maximum frequency of tasks
        int maxFreq = 0;
        for (auto [task, freq] : taskFreq) {
            maxFreq = max(maxFreq, freq);
        }

        // Count the number of tasks with maximum frequency
        int maxFreqCount = 0;
        for (auto [task, freq] : taskFreq) {
            if (freq == maxFreq) {
                maxFreqCount++;
            }
        }

        // Calculate the minimum intervals required
        int intervals = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return max(static_cast<int>(tasks.size()), intervals);
    }
};