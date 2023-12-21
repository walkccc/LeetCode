class Solution {
 public:
  vector<string> getWordsInLongestSubsequence(int n, vector<string>& words,
                                              vector<int>& groups) {
    vector<string> ans;
    // dp[i] := the length of the longest subsequence ending in the `words[i]`
    vector<int> dp(n, 1);
    // prev[i] := the best index of words[i]
    vector<int> prev(n, -1);

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        if (groups[i] == groups[j])
          continue;
        if (words[i].length() != words[j].length())
          continue;
        if (hammingDist(words[i], words[j]) != 1)
          continue;
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }

    // Find the last index of the subsequence.
    int index = ranges::max_element(dp) - dp.begin();
    while (index != -1) {
      ans.push_back(words[index]);
      index = prev[index];
    }

    return {ans.rbegin(), ans.rend()};
  }

 private:
  int hammingDist(const string& s1, const string& s2) {
    int dist = 0;
    for (int i = 0; i < s1.length(); ++i)
      if (s1[i] != s2[i])
        ++dist;
    return dist;
  }
};
