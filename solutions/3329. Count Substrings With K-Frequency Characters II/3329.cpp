class Solution {
 public:
  long long numberOfSubstrings(string s, int k) {
    const int n = s.length();
    long ans = n * static_cast<long>(n + 1) / 2;
    vector<int> count(26);

    for (int l = 0, r = 0; r < n; ++r) {
      const int c = s[r];
      ++count[c - 'a'];
      while (count[c - 'a'] == k)
        --count[s[l++] - 'a'];
      ans -= r - l + 1;
    }

    return ans;
  }
};
