class Solution:
  def maxSubstringLength(self, s: str, k: int) -> bool:
    n = len(s)
    first = [n] * 26
    last = [-1] * 26
    # dp[i] := the maximum disjoint special substrings for the first i letters
    dp = [0] * (n + 1)
    seenOrder = []

    for i, c in enumerate(s):
      a = ord(c) - ord('a')
      if first[a] == n:
        first[a] = i
        seenOrder.append(c)
      last[a] = i

    for c in seenOrder:
      a = ord(c) - ord('a')
      for j in range(first[a], last[a]):
        b = ord(s[j]) - ord('a')
        first[a] = min(first[a], first[b])
        last[a] = max(last[a], last[b])

    for i, c in enumerate(s):
      a = ord(c) - ord('a')
      if last[a] != i or (first[a] == 0 and i == n - 1):
        dp[i + 1] = dp[i]
      else:  # Start a new special substring.
        dp[i + 1] = max(dp[i], 1 + dp[first[a]])

    return dp[n] >= k
