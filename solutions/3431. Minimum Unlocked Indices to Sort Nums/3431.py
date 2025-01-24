class Solution:
  def minUnlockedIndices(self, nums: list[int], locked: list[int]) -> int:
    first2 = next((i for i, x in enumerate(nums) if x == 2), -1)
    first3 = next((i for i, x in enumerate(nums) if x == 3), -1)
    last1 = next((i for i, x in reversed(list(enumerate(nums))) if x == 1), -1)
    last2 = next((i for i, x in reversed(list(enumerate(nums))) if x == 2), -1)
    if first3 != -1 and last1 != -1 and first3 < last1:
      return -1
    return (sum(locked[i] == 1 for i in range(first2, last1)
                if first2 != -1 and last1 != -1) +
            sum(locked[i] == 1 for i in range(first3, last2)
                if first3 != -1 and last2 != -1))
