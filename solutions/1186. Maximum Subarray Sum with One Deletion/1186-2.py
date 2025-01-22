class Solution:
  # Very similar to 53. Maximum Subarray
  def maximumSum(self, arr: list[int]) -> int:
    ans = -math.inf
    zero = -math.inf  # no deletion
    one = -math.inf   # <= 1 deletion

    for a in arr:
      one = max(a, one + a, zero)
      zero = max(a, zero + a)
      ans = max(ans, one)

    return ans
