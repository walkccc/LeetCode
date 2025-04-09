class Solution:
  def countSubstrings(self, s: str) -> int:
    ans = 0
    # dp[num][rem] := the number of substrings so far that have a remainder of
    # `rem` when divided by `num`
    dp = [[0] * 10 for _ in range(10)]

    for c in s:
      digit = int(c)
      newDp = [[0] * 10 for _ in range(10)]
      for num in range(1, 10):
        for rem in range(num):
          newDp[num][(rem * 10 + digit) % num] += dp[num][rem]
        newDp[num][digit % num] += 1
      dp = newDp
      ans += dp[digit][0]

    return ans
