class Solution:
  def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
    # dp[i] := min steps to reach i at previous round
    dp = {-1: 0}

    arr2.sort()

    for a in arr1:
      nextDp = defaultdict(lambda: math.inf)
      for val, steps in dp.items():
        # it's possible to use the value in arr1
        if a > val:
          nextDp[a] = min(nextDp[a], steps)
        # also try the value in arr2
        i = bisect_right(arr2, val)
        if i < len(arr2):
          nextDp[arr2[i]] = min(nextDp[arr2[i]], steps + 1)
      if not nextDp:
        return -1
      dp = nextDp

    return min(dp.values())
