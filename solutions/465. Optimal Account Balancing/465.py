class Solution:
  def minTransfers(self, transactions: list[list[int]]) -> int:
    balance = [0] * 21

    for u, v, amount in transactions:
      balance[u] -= amount
      balance[v] += amount

    debts = [b for b in balance if b]

    def dfs(s: int) -> int:
      while s < len(debts) and not debts[s]:
        s += 1
      if s == len(debts):
        return 0

      ans = math.inf

      for i in range(s + 1, len(debts)):
        if debts[i] * debts[s] < 0:
          debts[i] += debts[s]  # `debts[s]` is settled.
          ans = min(ans, 1 + dfs(s + 1))
          debts[i] -= debts[s]  # Backtrack.

      return ans

    return dfs(0)
