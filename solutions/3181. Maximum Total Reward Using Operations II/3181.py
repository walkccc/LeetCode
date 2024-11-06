class Solution:
  # Same as 3180. Maximum Total Reward Using Operations I
  def maxTotalReward(self, rewardValues: list[int]) -> int:
    dp = 1  # the possible rewards (initially, 0 is achievable)

    for num in sorted(rewardValues):
      # Remove the numbers >= the current number.
      smallerNums = dp & ((1 << num) - 1)
      dp |= smallerNums << num

    return dp.bit_length() - 1
