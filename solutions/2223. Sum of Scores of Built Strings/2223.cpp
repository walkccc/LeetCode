class Solution {
 public:
  long long sumScores(string s) {
    const int n = s.length();
    vector<int> z(n);
    // [l, r] := indices of the rightmost segment match
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; ++i) {
      if (i <= r)
        z[i] = min(r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }

    return accumulate(begin(z), end(z), 0LL) + n;
  }
};
