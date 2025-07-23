class Solution {
 public:
  int reverseDegree(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      const int reversePos = 26 - (s[i] - 'a');
      ans += reversePos * (i + 1);
    }
    return ans;
  }
};
