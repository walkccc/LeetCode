class Solution {
 public:
  long long appealSum(string s) {
    long long ans = 0;
    int dp = 0;  // # of appeal of string ending at current index
    vector<int> lastOccurrence(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      dp += i - lastOccurrence[s[i] - 'a'];
      ans += dp;
      lastOccurrence[s[i] - 'a'] = i;
    }

    return ans;
  }
};
