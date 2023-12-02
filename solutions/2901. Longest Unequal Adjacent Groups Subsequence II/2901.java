class Solution {
  public List<String> getWordsInLongestSubsequence(int n, String[] words, int[] groups) {
    List<String> ans = new ArrayList<>();
    // dp[i] := the length of the longest subsequence ending in the `words[i]`
    int[] dp = new int[n];
    Arrays.fill(dp, 1);
    // prev[i] := the best index of words[i]
    int[] prev = new int[n];
    Arrays.fill(prev, -1);

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
    int index = getMaxIndex(dp);
    while (index != -1) {
      ans.add(words[index]);
      index = prev[index];
    }

    Collections.reverse(ans);
    return ans;
  }

  private int hammingDist(final String s1, final String s2) {
    int dist = 0;
    for (int i = 0; i < s1.length(); ++i)
      if (s1.charAt(i) != s2.charAt(i))
        ++dist;
    return dist;
  }

  private int getMaxIndex(int[] dp) {
    int maxIndex = 0;
    for (int i = 0; i < dp.length; ++i)
      if (dp[i] > dp[maxIndex])
        maxIndex = i;
    return maxIndex;
  }
}
