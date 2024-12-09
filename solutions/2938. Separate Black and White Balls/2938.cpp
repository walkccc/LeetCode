class Solution {
 public:
  long long minimumSteps(string s) {
    long ans = 0;
    int ones = 0;

    for (const char c : s)
      if (c == '1')
        ++ones;
      else  // Move 1s to the front of the current '0'.
        ans += ones;

    return ans;
  }
};
