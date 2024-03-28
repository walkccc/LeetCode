class Solution:
  def maximumOr(self, nums: List[int], k: int) -> int:
    n = len(nums)
    # prefix[i] := nums[0] | nums[1] | ... | nums[i - 1]
    prefix = [0] * n
    # suffix[i] := nums[i + 1] | nums[i + 2] | ... nums[n - 1]
    suffix = [0] * n

    for i in range(1, n):
      prefix[i] = prefix[i - 1] | nums[i - 1]

    for i in range(n - 2, -1, -1):
      suffix[i] = suffix[i + 1] | nums[i + 1]

    # For each num, greedily shift it left by k bits.
    return max(p | num << k | s for num, p, s in zip(nums, prefix, suffix))
