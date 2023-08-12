class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    // # of chars to be flilpped to make substring so far monotone increasing
    int dp = 0;
    int count1 = 0;

    for (const char c : s)
      if (c == '0')
        // 1. Flip '0'.
        // 2. Keep '0' and flip previous '1's.
        dp = min(dp + 1, count1);
      else
        ++count1;

    return dp;
  }
};
