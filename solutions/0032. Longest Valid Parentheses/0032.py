class Solution:
  def longestValidParentheses(self, s: str) -> int:
    s2 = ')' + s
    # dp[i] := length of longest valid parentheses substring of s2[1..i]
    dp = [0] * len(s2)

    for i in range(1, len(s2)):
      if s2[i] == ')' and s2[i - dp[i - 1] - 1] == '(':
        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2

    return max(dp)
