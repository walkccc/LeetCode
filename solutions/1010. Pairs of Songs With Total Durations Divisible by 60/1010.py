class Solution:
  def numPairsDivisibleBy60(self, time: list[int]) -> int:
    ans = 0
    count = [0] * 60

    for t in time:
      t %= 60
      ans += count[(60 - t) % 60]
      count[t] += 1

    return ans
