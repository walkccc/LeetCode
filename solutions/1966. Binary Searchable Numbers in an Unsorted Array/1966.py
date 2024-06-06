class Solution:
  def binarySearchableNumbers(self, nums: List[int]) -> int:
    n = len(nums)
    # prefixMaxs[i] := max(nums[0..i))
    prefixMaxs = [0] * n
    # suffixMins[i] := min(nums[i + 1..n))
    suffixMins = [0] * n

    # Fill in `prefixMaxs`.
    prefixMaxs[0] = -math.inf
    for i in range(1, n):
      prefixMaxs[i] = max(prefixMaxs[i - 1], nums[i - 1])

    # Fill in `suffixMins`.
    suffixMins[n - 1] = math.inf
    for i in range(n - 2, -1, -1):
      suffixMins[i] = min(suffixMins[i + 1], nums[i + 1])

    return sum(prefixMaxs[i] < nums[i] < suffixMins[i] for i in range(n))
