class Solution:
  def makeArrayIncreasing(self, arr1: list[int], arr2: list[int]) -> int:
    # dp[i] := the minimum steps to reach i at previous round
    dp = {-1: 0}

    arr2.sort()

    for a in arr1:
      nextDp = collections.defaultdict(lambda: math.inf)
      for val, steps in dp.items():
        # It's possible to use the value in the arr1.
        if a > val:
          nextDp[a] = min(nextDp[a], steps)
        # Also try the value in the arr2.
        i = bisect_right(arr2, val)
        if i < len(arr2):
          nextDp[arr2[i]] = min(nextDp[arr2[i]], steps + 1)
      if not nextDp:
        return -1
      dp = nextDp

    return min(dp.values())
