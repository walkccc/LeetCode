class Solution:
  def minimumMoney(self, transactions: list[list[int]]) -> int:
    ans = 0
    losses = 0

    # Before picking the final transaction, perform any transaction that raises
    # the required money.
    for cost, cashback in transactions:
      losses += max(0, cost - cashback)

    # Now, pick a transaction to be the final one.
    for cost, cashback in transactions:
      if cost > cashback:
        # The losses except this transaction: losses - (cost - cashback), so
        # add the cost of this transaction = losses - (cost - cashback) + cost.
        ans = max(ans, losses + cashback)
      else:
        # The losses except this transaction: losses, so add the cost of this
        # transaction = losses + cost.
        ans = max(ans, losses + cost)

    return ans
