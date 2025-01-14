class Solution:
  def maximumScore(self, nums: list[int], k: int) -> int:
    n = len(nums)
    ans = nums[k]
    mn = nums[k]
    i = k
    j = k

    # Greedily expand the window and decrease the minimum as slow as possible.
    while i > 0 or j < n - 1:
      if i == 0:
        j += 1
      elif j == n - 1:
        i -= 1
      elif nums[i - 1] < nums[j + 1]:
        j += 1
      else:
        i -= 1
      mn = min(mn, nums[i], nums[j])
      ans = max(ans, mn * (j - i + 1))

    return ans
