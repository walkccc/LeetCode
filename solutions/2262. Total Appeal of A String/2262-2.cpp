class Solution {
 public:
  long long appealSum(string s) {
    const int n = s.length();
    long long ans = 0;
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < n; ++i) {
      const int c = s[i] - 'a';
      ans += (i - lastSeen[c]) * (n - i);
      lastSeen[c] = i;
    }

    return ans;
  }
};
