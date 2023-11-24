class Solution {
 public:
  long long minimumSteps(string s) {
    long long ans = 0;
    int ones = 0;

    for (const char c : s)
      if (c == '1')
        ++ones;
      else  // Move `ones` to the front of current '0'.
        ans += ones;

    return ans;
  }
};
