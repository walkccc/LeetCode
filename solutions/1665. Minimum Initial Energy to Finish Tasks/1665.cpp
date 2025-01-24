class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    int ans = 0;
    int prevSaved = 0;

    ranges::sort(tasks, ranges::greater{},
                 [](const vector<int>& task) { return task[1] - task[0]; });

    for (const vector<int>& task : tasks) {
      const int actual = task[0];
      const int minimum = task[1];
      if (prevSaved < minimum) {
        ans += minimum - prevSaved;
        prevSaved = minimum - actual;
      } else {
        prevSaved -= actual;
      }
    }

    return ans;
  }
};
