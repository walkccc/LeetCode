class Solution:
  def countHomogenous(self, s: str) -> int:
    MOD = 1_000_000_007
    ans = 0
    count = 0
    currentChar = '@'

    for c in s:
      count = count + 1 if c == currentChar else 1
      currentChar = c
      ans += count
      ans %= MOD

    return ans
