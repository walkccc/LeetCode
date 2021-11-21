class Solution:
  def findPairs(self, nums: List[int], k: int) -> int:
    if k < 0:
      return 0

    ans = 0
    dict = {num: i for i, num in enumerate(nums)}

    for i, num in enumerate(nums):
      target = num + k
      if target in dict and dict[target] != i:
        ans += 1
        del dict[target]

    return ans
