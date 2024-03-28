class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> taskToNextAvailable;
    long long ans = 0;

    for (const int task : tasks) {
      ans = max(ans + 1, taskToNextAvailable[task]);
      taskToNextAvailable[task] = ans + space + 1;
    }

    return ans;
  }
};
