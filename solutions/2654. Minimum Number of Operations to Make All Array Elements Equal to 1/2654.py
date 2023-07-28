class Solution:
  def minOperations(self, nums: List[int]) -> int:
    n = len(nums)
    ones = nums.count(1)
    if ones > 0:
      return n - ones

    # ops to make the shortest subarray with a gcd == 1
    minOps = math.inf

    for i, g in enumerate(nums):
      for j in range(i + 1, n):
        g = math.gcd(g, nums[j])
        if g == 1:   # gcd(nums[i..j]:== 1
          minOps = min(minOps, j - i)
          break

    # After making the shortest subarray with `minOps`, need additional n - 1
    # ops to make other nums to 1.
    return -1 if minOps == math.inf else minOps + n - 1
