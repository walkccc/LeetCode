class Solution {
 public:
  long long appealSum(string s) {
    long long ans = 0;
    vector<int> lastOccurrence(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      ans += (i - lastOccurrence[s[i] - 'a']) * (s.length() - i);
      lastOccurrence[s[i] - 'a'] = i;
    }

    return ans;
  }
};
