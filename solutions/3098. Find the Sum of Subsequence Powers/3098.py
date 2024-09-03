class Solution:
  def sumOfPowers(self, nums: list[int], k: int) -> int:
    kMod = 1_000_000_007
    nums.sort()

    @functools.lru_cache(None)
    def dp(
            i: int, k: int, lastPickedIndex: int, firstIndex: int,
            secondIndex: int) -> int:
      if k == 0:
        return nums[secondIndex] - nums[firstIndex]
      if i == len(nums):
        return 0
      newFirstIndex = firstIndex
      newSecondIndex = secondIndex
      if firstIndex == -1:
        newFirstIndex = i
      elif secondIndex == -1:
        newSecondIndex = i
      elif nums[i] - nums[lastPickedIndex] < nums[secondIndex] - nums[firstIndex]:
        newFirstIndex = lastPickedIndex
        newSecondIndex = i
      pick = dp(i + 1, k - 1, i, newFirstIndex, newSecondIndex)
      skip = dp(i + 1, k, lastPickedIndex, firstIndex, secondIndex)
      return (pick + skip) % kMod

    return dp(0, k, -1, -1, -1)
