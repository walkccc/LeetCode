class Solution:
  def longestStrChain(self, words: list[str]) -> int:
    dp = {}

    for word in sorted(words, key=len):
      dp[word] = max(dp.get(word[:i] + word[i + 1:], 0) +
                     1 for i in range(len(word)))

    return max(dp.values())
