class Solution:
  def findPairs(self, nums: List[int], k: int) -> int:
    ans = 0
    numToIndex = {num: i for i, num in enumerate(nums)}

    for i, num in enumerate(nums):
      target = num + k
      if target in numToIndex and numToIndex[target] != i:
        ans += 1
        del numToIndex[target]

    return ans
