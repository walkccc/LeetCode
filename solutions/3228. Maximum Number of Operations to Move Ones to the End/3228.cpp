class Solution {
 public:
  int maxOperations(string s) {
    int ans = 0;
    int ones = 0;

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '1')
        ++ones;
      else if (i + 1 == s.length() || s[i + 1] == '1')
        ans += ones;

    return ans;
  }
};
