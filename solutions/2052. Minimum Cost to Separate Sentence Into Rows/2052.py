class Solution:
  def minimumCost(self, sentence: str, k: int) -> int:
    if len(sentence) <= k:
      return 0

    words = sentence.split()

    # dp[i] := min cost of first i words
    dp = [0] * (len(words) + 1)

    for i in range(1, len(words) + 1):
      n = len(words[i - 1])  # length of current row
      dp[i] = dp[i - 1] + (k - n)**2
      # gradually add words[j - 1], words[j - 2], ...
      for j in range(i - 1, 0, -1):
        n += len(words[j - 1]) + 1
        if n > k:
          break
        dp[i] = min(dp[i], dp[j - 1] + (k - n)**2)

    lastRowLen = len(words[-1])
    i = len(words) - 2  # greedily put words into last row

    while i > 0 and lastRowLen + len(words[i]) + 1 <= k:
      lastRowLen += len(words[i]) + 1
      i -= 1

    return min(dp[i + 1:len(words)])
