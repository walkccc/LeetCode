class Solution:
  def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
    n = len(regular)
    ans = [0] * n
    # min cost to reach current stop in regular route
    dpReg = 0
    # min cost to reach current stop in express route
    dpExp = expressCost

    for i in range(n):
      prevReg = dpReg
      prevExp = dpExp
      dpReg = min(prevReg + regular[i], prevExp + 0 + regular[i])
      dpExp = min(prevReg + expressCost + express[i], prevExp + express[i])
      ans[i] = min(dpReg, dpExp)

    return ans
