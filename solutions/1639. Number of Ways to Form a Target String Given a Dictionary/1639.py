class Solution:
  def numWays(self, words: List[str], target: str) -> int:
    kMod = 1_000_000_007
    wordLength = len(words[0])
    # dp[i][j] := # of ways to form first i characters of target using j first characters in each word
    dp = [[0] * (wordLength + 1) for _ in range(len(target) + 1)]
    # counts[j] := count map for words[i][j] where 0 <= i < len(words)
    counts = [collections.Counter() for _ in range(wordLength)]

    for i in range(wordLength):
      for word in words:
        counts[i][word[i]] += 1

    # dp(i, j) := # of ways to form target[i:] using word[j:]
    @functools.lru_cache(None)
    def dp(i: int, j: int):
      if i == len(target):
        return 1
      if j == wordLength:
        return 0
      return (dp(i + 1, j + 1) * counts[j][target[i]] + dp(i, j + 1)) % kMod

    return dp(0, 0)
