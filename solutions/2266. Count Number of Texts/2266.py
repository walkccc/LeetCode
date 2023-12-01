class Solution:
  def countTexts(self, pressedKeys: str) -> int:
    kMod = 1_000_000_007
    n = len(pressedKeys)
    # dp[i] := the number of possible text messages of pressedKeys[i..n)
    dp = [0] * n + [1]

    def isSame(s: str, i: int, k: int) -> bool:
      """Returns true if s[i..i + k) are the same digits."""
      if i + k > len(s):
        return False
      for j in range(i + 1, i + k):
        if s[j] != s[i]:
          return False
      return True

    for i in reversed(range(n)):
      dp[i] = dp[i + 1]
      if isSame(pressedKeys, i, 2):
        dp[i] += dp[i + 2]
      if isSame(pressedKeys, i, 3):
        dp[i] += dp[i + 3]
      if (pressedKeys[i] == '7' or pressedKeys[i] == '9') and \
              isSame(pressedKeys, i, 4):
        dp[i] += dp[i + 4]
      dp[i] %= kMod

    return dp[0]
