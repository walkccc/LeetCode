class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0;
    int zeros = 0;
    int ones = 0;

    for (const char c : s) {
      if (c == '0') {
        zeros = ones > 0 ? 1 : zeros + 1;
        ones = 0;
      } else {  // c == '1'
        ++ones;
      }
      if (zeros >= ones)
        ans = max(ans, ones);
    }

    return ans * 2;
  }
};
