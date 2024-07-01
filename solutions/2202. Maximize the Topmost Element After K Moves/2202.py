class Solution:
  def maximumTop(self, nums: List[int], k: int) -> int:
    n = len(nums)
    # After taking k elements, if we're left something, then we return nums[k]
    # Otherwise, return -1.
    if k == 0 or k == 1:
      return -1 if n == k else nums[k]
    # Remove then add even number of times.
    if n == 1:
      return -1 if k & 1 else nums[0]
    # Take min(n, k - 1) elements and put the largest one back.
    maxi = max(nums[:min(n, k - 1)])
    if k >= n:
      return maxi
    return max(maxi, nums[k])
