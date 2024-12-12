class FenwickTree:
  def __init__(self, n: int):
    self.vals = [0] * (n + 1)

  def maximize(self, i: int, val: int) -> None:
    """Updates the maximum sum of subsequence ending in (i - 1) with `val`."""
    while i < len(self.vals):
      self.vals[i] = max(self.vals[i], val)
      i += FenwickTree.lowbit(i)

  def get(self, i: int) -> int:
    """Returns the maximum sum of subsequence ending in (i - 1)."""
    res = 0
    while i > 0:
      res = max(res, self.vals[i])
      i -= FenwickTree.lowbit(i)
    return res

  @staticmethod
  def lowbit(i: int) -> int:
    return i & -i


class Solution:
  def maxBalancedSubsequenceSum(self, nums: list[int]) -> int:
    # Let's define maxSum[i] := subsequence with the maximum sum ending in i
    # By observation:
    #    nums[i] - nums[j] >= i - j
    # => nums[i] - i >= nums[j] - j
    # So, if nums[i] - i >= nums[j] - j, where i > j,
    # maxSum[i] = max(maxSum[i], maxSum[j] + nums[i])
    ans = -math.inf
    tree = FenwickTree(len(nums))

    for _, i in sorted([(num - i, i) for i, num in enumerate(nums)]):
      subseqSum = tree.get(i) + nums[i]
      tree.maximize(i + 1, subseqSum)
      ans = max(ans, subseqSum)

    return ans
