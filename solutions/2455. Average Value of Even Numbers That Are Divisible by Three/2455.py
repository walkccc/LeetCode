class Solution:
  def averageValue(self, nums: list[int]) -> int:
    summ = 0
    count = 0

    for num in nums:
      if num % 6 == 0:
        summ += num
        count += 1

    return 0 if count == 0 else summ // count
