class Solution:
  def maximumWealth(self, accounts: list[list[int]]) -> int:
    return max(map(sum, accounts))
