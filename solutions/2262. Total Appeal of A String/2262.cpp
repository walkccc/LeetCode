class Solution {
 public:
  long long appealSum(string s) {
    long long ans = 0;
    // total appeal of all substrings ending at the index so far
    int dp = 0;
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      //   total appeal of all substrings ending at s[i]
      // = total appeal of all substrings ending at s[i - 1]
      // + # of substrings ending at s[i] that contain only this s[i]
      const int c = s[i] - 'a';
      dp += i - lastSeen[c];
      ans += dp;
      lastSeen[c] = i;
    }

    return ans;
  }
};
