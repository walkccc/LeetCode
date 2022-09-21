class Solution:
  def maximumTop(self, nums: List[int], k: int) -> int:
    n = len(nums)
    # after taking k elements, if we're left something, then we return nums[k]
    # otherwise return -1
    if k == 0 or k == 1:
      return -1 if n == k else nums[k]
    # (remove then add) even times
    if n == 1:
      return -1 if k & 1 else nums[0]
    # take min(n, k - 1) elements and put back the largest one
    maxi = max(nums[:min(n, k - 1)])
    if k >= n:
      return maxi
    return max(maxi, nums[k])
