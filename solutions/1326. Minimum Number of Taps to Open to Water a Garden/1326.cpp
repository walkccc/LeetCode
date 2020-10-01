class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> nums(n + 1);

    for (int i = 0; i <= n; ++i) {
      int l = max(0, i - ranges[i]);
      int r = min(n, i + ranges[i]);
      nums[l] = max(nums[l], r - l);
    }

    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < n; i++) {
      farthest = max(farthest, i + nums[i]);
      if (i == end) {
        ++ans;
        end = farthest;
      }
    }

    return end == n ? ans : -1;
  }
};