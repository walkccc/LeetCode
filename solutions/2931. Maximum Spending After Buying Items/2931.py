class Solution:
  def maxSpending(self, values: list[list[int]]) -> int:
    items = sorted(item for shop in values for item in shop)
    return sum(item * d for d, item in enumerate(items, 1))
