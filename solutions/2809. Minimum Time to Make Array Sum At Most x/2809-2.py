class Solution:
  def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
    n = len(nums1)
    # dp[j] := the maximum reduced value if we do j operations on the numbers
    # so far
    dp = [0] * (n + 1)
    sum1 = sum(nums1)
    sum2 = sum(nums2)

    for i, (num2, num1) in enumerate(sorted(zip(nums2, nums1)), 1):
      for j in range(i, 0, -1):
        dp[j] = max(
            # the maximum reduced value if we do j operations on the first
            # i - 1 numbers
            dp[j],
            # the maximum reduced value if we do j - 1 operations on the first
            # i - 1 numbers + making the i-th number of `nums1` to 0 at the
            # j-th operation
            dp[j - 1] + num2 * j + num1
        )

    for op in range(n + 1):
      if sum1 + sum2 * op - dp[op] <= x:
        return op

    return -1
