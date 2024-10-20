class Solution:
  def numberOfNodes(self, n: int, queries: list[int]) -> int:
    # flipped[i] := True if we should flip all the values in the subtree rooted
    # at i
    flipped = [False] * (n + 1)

    for query in queries:
      flipped[query] = flipped[query] ^ True

    def dfs(label: int, value: int) -> int:
      if label > n:
        return 0
      value ^= flipped[label]
      return value + dfs(label * 2, value) + dfs(label * 2 + 1, value)

    return dfs(1, 0)
