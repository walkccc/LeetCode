class Solution:
  def minCostII(self, costs: List[List[int]]) -> int:
    prevIndex = -1  # the previous minimum index
    prevMin1 = 0    # minimum cost so far
    prevMin2 = 0    # 2nd minimum cost so far

    for cost in costs:   # O(n)
      index = -1  # the painted index s.t. achieve the minimum cost after painting current house
      min1 = math.inf  # the minimum cost after painting current house
      min2 = math.inf  # the 2nd minimum cost after painting current house
      for i, cst in enumerate(cost):   # O(k)
        theCost = cst + (prevMin2 if i == prevIndex else prevMin1)
        if theCost < min1:
          index = i
          min2 = min1
          min1 = theCost
        elif theCost < min2:   # min1 <= theCost < min2
          min2 = theCost

      prevIndex = index
      prevMin1 = min1
      prevMin2 = min2

    return prevMin1
