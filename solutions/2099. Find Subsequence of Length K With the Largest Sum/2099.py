class Solution:
  def maxSubsequence(self, nums: list[int], k: int) -> list[int]:
    ans = []
    threshold = sorted(nums)[-k]
    larger = sum(num > threshold for num in nums)
    equal = k - larger

    for num in nums:
      if num > threshold:
        ans.append(num)
      elif num == threshold and equal:
        ans.append(num)
        equal -= 1

    return ans
