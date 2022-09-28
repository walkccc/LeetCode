class Solution {
 public:
  int balancedString(string s) {
    const int n = s.length();
    const int k = n / 4;
    int ans = n;
    vector<int> count(128);

    for (const char c : s)
      ++count[c];

    for (int i = 0, j = 0; i < n; ++i) {
      --count[s[i]];
      while (j < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k &&
             count['R'] <= k) {
        ans = min(ans, i - j + 1);
        ++count[s[j]];
        ++j;
      }
    }

    return ans;
  }
};
