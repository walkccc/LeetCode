class Solution:
  def findKDistantIndices(self, nums: list[int], key: int, k: int) -> list[int]:
    n = len(nums)
    ans = []

    j = 0
    for i in range(n):
      # the first index j s.t. nums[j] == key and j >= i - k
      while j < n and (nums[j] != key or j < i - k):
        j += 1
      if j == n:
        break
      if abs(i - j) <= k:
        ans.append(i)

    return ans
