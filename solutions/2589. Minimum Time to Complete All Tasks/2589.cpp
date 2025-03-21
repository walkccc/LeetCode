class Solution {
 public:
  int findMinimumTime(vector<vector<int>>& tasks) {
    constexpr int kMax = 2000;
    vector<bool> running(kMax + 1);

    // Sort tasks by end.
    sort(
        tasks.begin(), tasks.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    for (const vector<int>& task : tasks) {
      const int start = task[0];
      const int end = task[1];
      const int duration = task[2];
      int neededDuration = duration - count(running.begin() + start,
                                            running.begin() + end + 1, true);
      // Greedily run the task as late as possible so that later tasks can run
      // simultaneously.
      for (int i = end; neededDuration > 0; --i) {
        if (!running[i]) {
          running[i] = true;
          --neededDuration;
        }
      }
    }

    return ranges::count(running, true);
  }
};
