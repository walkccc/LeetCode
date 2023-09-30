class Solution:
  def findSmallestInteger(self, nums: List[int], value: int) -> int:
    count = collections.Counter([num % value for num in nums])

    for i in range(len(nums)):
      if count[i % value] == 0:
        return i
      count[i % value] -= 1

    return len(nums)
