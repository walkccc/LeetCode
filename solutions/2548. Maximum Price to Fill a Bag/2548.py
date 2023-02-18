class Solution:
  def maxPrice(self, items: List[List[int]], capacity: int) -> float:
    ans = 0

    # Sort items based on price//weight.
    for price, weight in sorted(items, key=lambda x: -x[0] / x[1]):
      # The bag is filled.
      if capacity <= weight:
        return ans + price * capacity / weight
      ans += price
      capacity -= weight

    return -1
