class Solution:
  def minMaxSums(self, nums: list[int], k: int) -> int:
    # In a sorted array, nums[i] will be
    #   1. The maximum for subsequences formed by nums[0..i].
    #   2. The minimum for subsequences formed by nums[i..n - 1].
    #
    # The number of times nums[i] is the maximum is the same as the number of
    # times nums[n - 1 - i] is the minimum, due to the symmetry in subsequences
    # derived from the sorted order.
    #
    # To calculate the contribution of nums[i], we need to find the number of
    # ways to select at most (k - 1) elements from the range of indices where
    # nums[i] is the smallest or nums[n - 1 - i] is the largest.
    MOD = 1_000_000_007
    n = len(nums)

    def getComb(n: int, k: int) -> list[list[int]]:
      """C(n, k) = C(n - 1, k) + C(n - 1, k - 1)"""
      comb = [[0] * (k + 1) for _ in range(n + 1)]
      for i in range(n + 1):
        comb[i][0] = 1
      for i in range(1, n + 1):
        for j in range(1, k + 1):
          comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD
      return comb

    comb = getComb(n, k - 1)
    ans = 0

    nums.sort()

    # i: available numbers from the left of nums[i] or
    #    available numbers from the right of nums[-1 - i]
    for i in range(n):
      count = 0
      for j in range(k):  # selected numbers
        count = (count + comb[i][j]) % MOD
      ans += nums[i] * count
      ans += nums[-1 - i] * count
      ans %= MOD

    return ans
