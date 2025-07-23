class Solution:
  def minimumTime(self, nums1: list[int], nums2: list[int], x: int) -> int:
    n = len(nums1)
    # dp[i][j] := the maximum reduced value if we do j operations on the first
    # i numbers
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    sum1 = sum(nums1)
    sum2 = sum(nums2)

    for i, (num2, num1) in enumerate(sorted(zip(nums2, nums1)), 1):
      for j in range(1, i + 1):
        dp[i][j] = max(
            # the maximum reduced value if we do j operations on the first
            # i - 1 numbers
            dp[i - 1][j],
            # the maximum reduced value if we do j - 1 operations on the first
            # i - 1 numbers + making the i-th number of `nums1` to 0 at the
            # j-th operation
            dp[i - 1][j - 1] + num2 * j + num1
        )

    for op in range(n + 1):
      if sum1 + sum2 * op - dp[n][op] <= x:
        return op

    return -1
