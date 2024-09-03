class Solution {
 public:
  int takeCharacters(string s, int k) {
    const int n = s.length();
    int ans = n;
    vector<int> count(3);

    for (const char c : s)
      ++count[c - 'a'];

    if (count[0] < k || count[1] < k || count[2] < k)
      return -1;

    for (int l = 0, r = 0; r < n; ++r) {
      --count[s[r] - 'a'];
      while (count[s[r] - 'a'] < k)
        ++count[s[l++] - 'a'];
      ans = min(ans, n - (r - l + 1));
    }

    return ans;
  }
};
