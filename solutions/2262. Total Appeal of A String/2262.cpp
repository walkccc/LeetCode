class Solution {
 public:
  long long appealSum(string s) {
    long long ans = 0;
    // the total appeal of all substrings ending in the index so far
    int dp = 0;
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      //   the total appeal of all substrings ending in s[i]
      // = the total appeal of all substrings ending in s[i - 1]
      // + the number of substrings ending in s[i] that contain only this s[i]
      const int c = s[i] - 'a';
      dp += i - lastSeen[c];
      ans += dp;
      lastSeen[c] = i;
    }

    return ans;
  }
};
