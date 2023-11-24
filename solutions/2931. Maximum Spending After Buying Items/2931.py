class Solution:
  def maxSpending(self, values: List[List[int]]) -> int:
    items = sorted(item for shop in values for item in shop)
    return sum(item * d for d, item in enumerate(items, 1))
