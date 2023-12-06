class Solution:
  def numWays(self, words: List[str], target: str) -> int:
    kMod = 1_000_000_007
    wordLength = len(words[0])
    # counts[j] := the count map of words[i][j], where 0 <= i < |words|
    counts = [collections.Counter() for _ in range(wordLength)]

    for i in range(wordLength):
      for word in words:
        counts[i][word[i]] += 1

    @functools.lru_cache(None)
    def dp(i: int, j: int):
      """Returns the number of ways to form target[i..n) using word[j..n). """
      if i == len(target):
        return 1
      if j == wordLength:
        return 0
      return (dp(i + 1, j + 1) * counts[j][target[i]] + dp(i, j + 1)) % kMod

    return dp(0, 0)
