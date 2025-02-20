class Solution:
  def beautifulSplits(self, nums: list[int]) -> int:
    n = len(nums)
    # z[start][i] := the z array of nums[i..n) with respect to nums[start..n)
    z = [self._zFunction(nums, start)
         for start in range(n)]
    # nums1 | nums2 | nums3 = nums[0..i] | nums[i + 1..j] | nums[j + 1..n - 1]
    return sum((j - i >= i + 1 and z[0][i + 1] >= i + 1)  # nums1 is a prefix of nums2
               or z[i + 1][j + 1] >= j - i  # nums2 is a suffix of nums3.
               for i in range(n - 2)
               for j in range(i + 1, n - 1))

  def _zFunction(self, nums: list[int], start: int) -> list[int]:
    """
    Returns the z array, where z[i] is the length of the longest prefix of
    nums[i..n) which is also a prefix of nums[start..n).
    """
    n = len(nums)
    z = [0] * n
    l = start
    r = start
    for i in range(1 + start, n):
      if i < r:
        z[i] = min(r - i, z[i - l + start])
      while i + z[i] < n and nums[z[i] + start] == nums[i + z[i]]:
        z[i] += 1
      if i + z[i] > r:
        l = i
        r = i + z[i]
    return z
