class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    n = len(s)
    wordSet = set(wordDict)
    # dp[i] := True if s[0..i) can be segmented
    dp = [True] + [False] * n

    for i in range(1, n + 1):
      for j in range(i):
        # s[0..j) can be segmented and s[j..i) is in the `wordSet`, so s[0..i)
        # can be segmented.
        if dp[j] and s[j:i] in wordSet:
          dp[i] = True
          break

    return dp[n]
