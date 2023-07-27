class Solution {
 public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
    int ans = logs[0][0];
    int maxWorkingTime = logs[0][1];

    for (int i = 1; i < logs.size(); ++i) {
      const int id = logs[i][0];
      const int workingTime = logs[i][1] - logs[i - 1][1];
      if (workingTime > maxWorkingTime) {
        ans = id;
        maxWorkingTime = workingTime;
      } else if (workingTime == maxWorkingTime) {
        ans = min(ans, id);
      }
    }

    return ans;
  }
};
