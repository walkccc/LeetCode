class Solution:
  def maxNumberOfAlloys(self, n: int, k: int, budget: int,
                        composition: list[list[int]], stock: list[int],
                        costs: list[int]) -> int:
    l = 1
    r = 1_000_000_000

    def isPossible(m: int) -> bool:
      """Returns True if it's possible to create `m` alloys by using any machine."""
      # Try all the possible machines.
      for machine in composition:
        requiredMoney = 0
        for j in range(n):
          requiredUnits = max(0, machine[j] * m - stock[j])
          requiredMoney += requiredUnits * costs[j]
        if requiredMoney <= budget:
          return True
      return False

    while l < r:
      m = (l + r) // 2
      if isPossible(m):
        l = m + 1
      else:
        r = m

    return l - 1
