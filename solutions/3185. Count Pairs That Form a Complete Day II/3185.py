class Solution:
  # Same as 3184. Count Pairs That Form a Complete Day I
  def countCompleteDayPairs(self, hours: list[int]) -> int:
    ans = 0
    count = [0] * 24

    for hour in hours:
      ans += count[(24 - hour % 24) % 24]
      count[hour % 24] += 1

    return ans
