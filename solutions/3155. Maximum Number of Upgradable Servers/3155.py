class Solution:
  def maxUpgrades(self, count: List[int], upgrade: List[int], sell: List[int], money: List[int]) -> List[int]:
    # If there's enough money, upgrade all servers; otherwise, optimize by
    # upgrading x servers. We have x * upgrade <= money + (count - x) * sell.
    # Therefore, x = (money + count * sell) / (sell + upgrade).
    return [min(c, (m + c * s) // (s + u)) for c, u, s, m in zip(count, upgrade, sell, money)]
