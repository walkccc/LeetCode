class Solution {
 public:
  int uniqueLetterString(string s) {
    int ans = 0;
    // # of unique letters in all substrings ending at the index so far
    int dp = 0;
    vector<int> lastCount(26);
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      const int c = s[i] - 'A';
      const int newCount = i - lastSeen[c];
      // Minus the duplicates.
      dp -= lastCount[c];
      // Add count of s[lastSeen[c] + 1..i], s[lastSeen[c] + 2..i], ..., s[i].
      dp += newCount;
      lastCount[c] = newCount;
      lastSeen[c] = i;
      ans += dp;
    }

    return ans;
  }
};
