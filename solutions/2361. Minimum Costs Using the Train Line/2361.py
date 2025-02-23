class Solution:
  def minimumCosts(
      self,
      regular: list[int],
      express: list[int],
      expressCost: int,
  ) -> list[int]:
    n = len(regular)
    ans = [0] * n
    # the minimum cost to reach the current stop in a regular route
    dpReg = 0
    # the minimum cost to reach the current stop in an express route
    dpExp = expressCost

    for i in range(n):
      prevReg = dpReg
      prevExp = dpExp
      dpReg = min(prevReg + regular[i], prevExp + 0 + regular[i])
      dpExp = min(prevReg + expressCost + express[i], prevExp + express[i])
      ans[i] = min(dpReg, dpExp)

    return ans
