class Solution:
  def maxOutput(self, n: int, edges: list[list[int]], price: list[int]) -> int:
    ans = 0
    tree = [[] for _ in range(n)]
    maxSums = [0] * n  # maxSums[i] := the maximum the sum of path rooted at i

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def maxSum(u: int, prev: int) -> int:
      maxChildSum = 0
      for v in tree[u]:
        if v != prev:
          maxChildSum = max(maxChildSum, maxSum(v, u))
      maxSums[u] = price[u] + maxChildSum
      return maxSums[u]

    # Precalculate `maxSums`.
    maxSum(0, -1)

    def reroot(u: int, prev: int, parentSum: int) -> None:
      nonlocal ans
      # Get the top two subtree sums and the top one node index.
      maxSubtreeSum1 = 0
      maxSubtreeSum2 = 0
      maxNode = -1
      for v in tree[u]:
        if v == prev:
          continue
        if maxSums[v] > maxSubtreeSum1:
          maxSubtreeSum2 = maxSubtreeSum1
          maxSubtreeSum1 = maxSums[v]
          maxNode = v
        elif maxSums[v] > maxSubtreeSum2:
          maxSubtreeSum2 = maxSums[v]

      if len(tree[u]) == 1:
        ans = max(ans, parentSum, maxSubtreeSum1)

      for v in tree[u]:
        if v == prev:
          continue
        nextParentSum = (
            price[u] + max(parentSum, maxSubtreeSum2) if v == maxNode else
            price[u] + max(parentSum, maxSubtreeSum1))
        reroot(v, u, nextParentSum)

    reroot(0, -1, 0)
    return ans
