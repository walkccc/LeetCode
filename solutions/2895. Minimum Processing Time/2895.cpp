class Solution {
 public:
  int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    int ans = 0;
    ranges::sort(processorTime);
    ranges::sort(tasks, greater<>());

    // It's optimal to run each 4 longer tasks with a smaller processor time.
    // Therefore, for each processor, take the maximum of the sum of the
    // processor time and the largest assigned tasks[i].
    for (int i = 0; i < processorTime.size(); ++i)
      ans = max(ans, processorTime[i] + tasks[i * 4]);

    return ans;
  }
};
