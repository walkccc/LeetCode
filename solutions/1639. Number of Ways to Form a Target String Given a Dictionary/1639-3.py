class Solution:
  def numWays(self, words: list[str], target: str) -> int:
    kMod = 1_000_000_007
    # dp[i] := the number of ways to form the first i characters of `target`
    dp = [0] * (len(target) + 1)
    dp[0] = 1

    for j in range(len(words[0])):
      count = collections.Counter(word[j] for word in words)
      for i in range(len(target), 0, -1):
        dp[i] += dp[i - 1] * count[target[i - 1]]
        dp[i] %= kMod

    return dp[len(target)]
