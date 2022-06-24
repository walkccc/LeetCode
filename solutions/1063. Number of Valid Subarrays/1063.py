class Solution:
  def validSubarrays(self, nums: List[int]) -> int:
    # for each num in nums, each element x in the stack can be the leftmost
    # element s.t. [x, num] forms a valid subarray, so the len(stack) is
    # the # of valid subarrays ending at curr num
    #
    # e.g. nums = [1, 3, 2]
    # num = 1, stack = [1] . valid subarray is [1]
    # num = 3, stack = [1, 3] . valid subarrays are [1, 3], [3]
    # num = 2, stack = [1, 2] . valid subarrays are [1, 3, 2], [2]
    ans = 0
    stack = []

    for num in nums:
      while stack and stack[-1] > num:
        stack.pop()
      stack.append(num)
      ans += len(stack)

    return ans
