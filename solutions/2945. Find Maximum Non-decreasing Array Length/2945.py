class Solution:
  def findMaximumLength(self, nums: list[int]) -> int:
    n = len(nums)
    kInf = 10_000_000_000
    # prefix[i] := the sum of the first i nums
    prefix = list(itertools.accumulate(nums, initial=0))
    # dp[i] := the maximum number of elements in the increasing
    # sequence after processing the first i nums
    dp = [0] * (n + 1)
    # last[i] := the last sum after processing the first i nums
    last = [0] + [kInf] * n

    for i in range(n):
      j = self._findIndex(i, prefix, last)
      dp[i + 1] = max(dp[i], dp[j] + 1)
      last[i + 1] = prefix[i + 1] - prefix[j]

    return dp[n]

  def _findIndex(self, i: int, prefix: list[int], last: list[int]) -> int:
    """Returns the index in [0..i].

    Returns the maximum index j in [0..i] s.t.
    prefix[i + 1] - prefix[j] >= last[j].
    """
    for j in range(i, -1, -1):
      if prefix[i + 1] - prefix[j] >= last[j]:
        return j
