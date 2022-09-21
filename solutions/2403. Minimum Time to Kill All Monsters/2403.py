class Solution:
  def minimumTime(self, power: List[int]) -> int:
    n = len(power)
    maxMask = 1 << n
    # dp[i] := min # of days needed to defeat monsters,
    # where i is the bit representation of monsters
    dp = [math.inf] * maxMask
    dp[0] = 0

    for mask in range(1, maxMask):
      currentGain = mask.bit_count()
      for i in range(n):
        if mask >> i & 1:
          dp[mask] = min(dp[mask], dp[mask & ~(1 << i)] +
                         int(math.ceil(power[i] / currentGain)))

    return dp[-1]
