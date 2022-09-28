class Solution:
  def minimumMoney(self, transactions: List[List[int]]) -> int:
    ans = 0
    losses = 0

    # before picking the final transaction, perform any transaction that raises
    # the required money
    for cost, cashback in transactions:
      losses += max(0, cost - cashback)

    # now, pick a transaction to be the final one
    for cost, cashback in transactions:
      if cost > cashback:
        # losses except this transaction: losses - (cost - cashback),
        # so add cost of this transaction = losses - (cost - cashback) + cost
        ans = max(ans, losses + cashback)
      else:
        # losses except this transaction: losses,
        # so add cost of this transaction = losses + cost
        ans = max(ans, losses + cost)

    return ans
