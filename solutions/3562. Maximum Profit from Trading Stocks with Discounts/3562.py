class Solution:
  def maxProfit(
      self,
      n: int,
      present: list[int],
      future: list[int],
      hierarchy: list[list[int]],
      budget: int,
  ) -> int:
    tree = [[] for _ in range(n)]

    for u, v in hierarchy:
      tree[u - 1].append(v - 1)

    @functools.lru_cache(None)
    def dp(u: int, parent: int) -> tuple[list[int], list[int]]:
      noDiscount = [0] * (budget + 1)
      withDiscount = [0] * (budget + 1)

      for v in tree[u]:
        if v == parent:
          continue
        childNoDiscount, childWithDiscount = dp(v, u)
        noDiscount = self._merge(noDiscount, childNoDiscount)
        withDiscount = self._merge(withDiscount, childWithDiscount)

      newDp0 = noDiscount[:]
      newDp1 = noDiscount[:]

      # 1. Buy current node at full cost (no discount)
      fullCost = present[u]
      for b in range(fullCost, budget + 1):
        profit = future[u] - fullCost
        newDp0[b] = max(newDp0[b], withDiscount[b - fullCost] + profit)

      # 2. Buy current node at half cost (discounted by parent)
      halfCost = present[u] // 2
      for b in range(halfCost, budget + 1):
        profit = future[u] - halfCost
        newDp1[b] = max(newDp1[b], withDiscount[b - halfCost] + profit)

      return newDp0, newDp1

    return max(dp(0, -1)[0])

  def _merge(self, dpA: list[int], dpB: list[int]) -> list[int]:
    merged = [-math.inf] * len(dpA)
    for i, a in enumerate(dpA):
      for j in range(len(dpA) - i):
        merged[i + j] = max(merged[i + j], a + dpB[j])
    return merged
