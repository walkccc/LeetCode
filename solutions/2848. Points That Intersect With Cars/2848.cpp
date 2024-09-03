class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    constexpr int kMax = 100;
    int ans = 0;
    int runningSum = 0;
    vector<int> count(kMax + 2);

    for (const vector<int>& num : nums) {
      const int start = num[0];
      const int end = num[1];
      ++count[start];
      --count[end + 1];
    }

    for (int i = 1; i <= kMax; ++i) {
      runningSum += count[i];
      if (runningSum > 0)
        ++ans;
    }

    return ans;
  }
};
