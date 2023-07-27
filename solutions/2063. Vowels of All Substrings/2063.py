class Solution:
  def countVowels(self, word: str) -> int:
    # dp[i] := sum of the # of vowels of word[:i], ..., word[i - 1:i]
    dp = [0] * (len(word) + 1)

    for i, c in enumerate(word):
      dp[i + 1] = dp[i]
      if c in 'aeiou':
        dp[i + 1] += i + 1

    return sum(dp)
