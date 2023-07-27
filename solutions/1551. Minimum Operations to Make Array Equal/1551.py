class Solution:
  def minOperations(self, n: int) -> int:
    # Return i-th element of arr, where 1 <= i <= n.
    def arr(self, i: int) -> int:
      return (i - 1) * 2 + 1

    #     median := median of arr
    #   diffs[i] := median - arr[i] where i <= i <= n // 2
    #        ans := sum(diffs)
    # E.g.
    # n = 5, arr = [1, 3, 5, 7, 9], diffs = [4, 2]
    #        ans = (4 + 2) * 2 // 2 = 6
    # n = 6, arr = [1, 3, 5, 7, 9, 11], diffs = [5, 3, 1]
    #        ans = (5 + 1) * 3 // 2 = 9
    halfSize = n // 2
    median = (arr(n) + arr(1)) // 2
    firstDiff = median - arr(1)
    lastDiff = median - arr(halfSize)
    return (firstDiff + lastDiff) * halfSize // 2
