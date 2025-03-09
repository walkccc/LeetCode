class Solution:
  def minCost(self, arr: list[int], brr: list[int], k: int) -> int:
    def cost(arr: list[int], brr: list[int]) -> int:
      return sum(abs(a - b) for a, b in zip(arr, brr))
    return min(cost(arr, brr), cost(sorted(arr), sorted(brr)) + k)
