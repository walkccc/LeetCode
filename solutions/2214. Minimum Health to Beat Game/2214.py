class Solution:
  def minimumHealth(self, damage: list[int], armor: int) -> int:
    return 1 + sum(damage) - min(max(damage), armor)
