class Solution:
  def numFactoredBinaryTrees(self, arr: list[int]) -> int:
    kMod = 1_000_000_007
    n = len(arr)
    # dp[i] := the number of binary trees with arr[i] as the root
    dp = [1] * n
    arr.sort()
    numToIndex = {a: i for i, a in enumerate(arr)}

    for i, root in enumerate(arr):  # arr[i] is the root
      for j in range(i):
        if root % arr[j] == 0:  # arr[j] is the left subtree
          right = root // arr[j]
          if right in numToIndex:
            dp[i] += dp[j] * dp[numToIndex[right]]
            dp[i] %= kMod

    return sum(dp) % kMod
