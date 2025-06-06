class Solution:
  def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
    MAX = 100
    count = collections.Counter(nums)

    for i in range(1, MAX + 1):
      count[i] += count[i - 1]

    return [0 if num == 0 else count[num - 1]
            for num in nums]
