class Solution {
 public:
  int longestAwesome(string s) {
    int ans = 0;
    int prefix = 0;  // binary prefix
    vector<int> prefixToIndex(1024, s.length());
    prefixToIndex[0] = -1;

    for (int i = 0; i < s.length(); ++i) {
      prefix ^= 1 << s[i] - '0';
      ans = max(ans, i - prefixToIndex[prefix]);
      for (int j = 0; j < 10; ++j)
        ans = max(ans, i - prefixToIndex[prefix ^ 1 << j]);
      prefixToIndex[prefix] = min(prefixToIndex[prefix], i);
    }

    return ans;
  }
};
