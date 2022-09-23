class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    // dp[i][k] := length of optimal compression of s[i:] w/ at most k deletion
    dp.resize(s.length(), vector<int>(k + 1, kMax));
    return compression(s, 0, k);
  }

 private:
  constexpr static int kMax = 101;
  vector<vector<int>> dp;

  int compression(const string& s, int i, int k) {
    if (k < 0)
      return kMax;
    if (i == s.length() || s.length() - i <= k)
      return 0;
    if (dp[i][k] != kMax)
      return dp[i][k];

    int maxFreq = 0;  // max freq in s[i..j]
    vector<int> count(128);

    // make chars in s[i..j] be same
    // keep the char that has max freq in this range and remove other chars
    for (int j = i; j < s.length(); ++j) {
      maxFreq = max(maxFreq, ++count[s[j]]);
      dp[i][k] = min(dp[i][k],
                     getLength(maxFreq) +
                     compression(s, j + 1, k - (j - i + 1 - maxFreq)));
    }

    return dp[i][k];
  }

  int getLength(int maxFreq) {  // the length to compress `maxFreq`
    if (maxFreq == 1)
      return 1;  // c
    if (maxFreq < 10)
      return 2;  // [1-9]c
    if (maxFreq < 100)
      return 3;  // [1-9][0-9]c
    return 4;    // [1-9][0-9][0-9]c
  }
};
