class Solution:
  def numberOfPoints(self, nums: list[list[int]]) -> int:
    MAX = 100
    ans = 0
    runningSum = 0
    count = [0] * (MAX + 2)

    for start, end in nums:
      count[start] += 1
      count[end + 1] -= 1

    for i in range(1, MAX + 1):
      runningSum += count[i]
      if runningSum > 0:
        ans += 1

    return ans
