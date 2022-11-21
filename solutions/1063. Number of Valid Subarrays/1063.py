class Solution:
  def validSubarrays(self, nums: List[int]) -> int:
    # For each num in nums, each element x in the stack can be the leftmost
    # Element s.t. [x, num] forms a valid subarray, so the len(stack) is
    # The # Of valid subarrays ending at curr num
    #
    # E.g. nums = [1, 3, 2]
    # Num = 1, stack = [1] . valid subarray is [1]
    # Num = 3, stack = [1, 3] . valid subarrays are [1, 3], [3]
    # Num = 2, stack = [1, 2] . valid subarrays are [1, 3, 2], [2]
    ans = 0
    stack = []

    for num in nums:
      while stack and stack[-1] > num:
        stack.pop()
      stack.append(num)
      ans += len(stack)

    return ans
