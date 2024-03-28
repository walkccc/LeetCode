class Solution:
  def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
    # nums[i] + nums[j] == nums[j] + nums[i], so the condition that i < j
    # degrades to i != j and we can sort the array.
    nums.sort()

    def countLess(summ: int) -> int:
      res = 0
      i = 0
      j = len(nums) - 1
      while i < j:
        while i < j and nums[i] + nums[j] > summ:
          j -= 1
        res += j - i
        i += 1
      return res

    return countLess(upper) - countLess(lower - 1)
