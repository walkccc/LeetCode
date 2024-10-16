class Solution {
 public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    const int n = startTime.size();
    int ans = 0;

    for (int i = 0; i < n; ++i)
      if (startTime[i] <= queryTime && queryTime <= endTime[i])
        ++ans;

    return ans;
  }
};
