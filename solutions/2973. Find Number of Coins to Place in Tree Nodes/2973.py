class ChildCost:
  def __init__(self, cost: int):
    self.numNodes = 1
    self.maxPosCosts = [cost] if cost > 0 else []
    self.minNegCosts = [cost] if cost < 0 else []

  def update(self, childCost: 'ChildCost') -> None:
    self.numNodes += childCost.numNodes
    self.maxPosCosts.extend(childCost.maxPosCosts)
    self.minNegCosts.extend(childCost.minNegCosts)
    self.maxPosCosts.sort(reverse=True)
    self.minNegCosts.sort()
    self.maxPosCosts = self.maxPosCosts[:3]
    self.minNegCosts = self.minNegCosts[:2]

  def maxProduct(self) -> int:
    if self.numNodes < 3:
      return 1
    if not self.maxPosCosts:
      return 0
    res = 0
    if len(self.maxPosCosts) == 3:
      res = self.maxPosCosts[0] * self.maxPosCosts[1] * self.maxPosCosts[2]
    if len(self.minNegCosts) == 2:
      res = max(res,
                self.minNegCosts[0] * self.minNegCosts[1] * self.maxPosCosts[0])
    return res


class Solution:
  def placedCoins(self, edges: list[list[int]], cost: list[int]) -> list[int]:
    n = len(cost)
    ans = [0] * n
    tree = [[] for _ in range(n)]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def dfs(u: int, prev: int) -> None:
      res = ChildCost(cost[u])
      for v in tree[u]:
        if v != prev:
          res.update(dfs(v, u))
      ans[u] = res.maxProduct()
      return res

    dfs(0, -1)
    return ans
