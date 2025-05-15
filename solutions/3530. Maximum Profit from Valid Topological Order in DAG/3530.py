class Solution:
  def maxProfit(self, n: int, edges: list[list[int]], score: list[int]) -> int:
    # need[i] := the bitmask representing all nodes that must be placed before
    # node i
    need = [0] * n
    # dp[mask] := the maximum profit achievable by placing the set of nodes
    # represented by `mask`
    dp = [-1] * (1 << n)
    dp[0] = 0

    for u, v in edges:
      need[v] |= 1 << u

    # Iterate over all subsets of nodes (represented by bitmask `mask`)
    for mask in range(1 << n):
      if dp[mask] == -1:
        continue
      # Determine the position of the next node to be placed (1-based).
      pos = mask.bit_count() + 1
      # Try to place each node `i` that hasn't been placed yet.
      for i in range(n):
        if mask >> i & 1:
          continue
        # Check if all dependencies of node `i` are already placed.
        if (mask & need[i]) == need[i]:
          newMask = mask | 1 << i  # Mark node `i` as placed.
          dp[newMask] = max(dp[newMask], dp[mask] + score[i] * pos)

    return dp[-1]
