class Solution {
 public:
  int minimumTime(string s) {
    const int n = s.length();
    int ans = n;
    int left = 0;  // the minimum time to remove the illegal cars so far

    for (int i = 0; i < n; ++i) {
      left = min(left + (s[i] - '0') * 2, i + 1);
      ans = min(ans, left + n - 1 - i);
    }

    return ans;
  }
};
