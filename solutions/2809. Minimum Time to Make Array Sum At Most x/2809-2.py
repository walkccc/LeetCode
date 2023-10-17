class Solution:
  def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
    n = len(nums1)
    # dp[j] := max reduced value if we do j ops on the nums so far
    dp = [0] * (n + 1)
    sum1 = sum(nums1)
    sum2 = sum(nums2)

    for i, (num2, num1) in enumerate(sorted(zip(nums2, nums1)), 1):
      for j in range(i, 0, -1):
        dp[j] = max(
            # max reduced value if we do j ops on the first i - 1 nums
            dp[j],
            # max reduced value if we do j - 1 ops on the first i - 1 nums +
            # making i-th num of nums1 to 0 at j-th operation
            dp[j - 1] + num2 * j + num1
        )

    for op in range(n + 1):
      if sum1 + sum2 * op - dp[op] <= x:
        return op

    return -1
