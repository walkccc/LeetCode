class Solution:
  def timeRequiredToBuy(self, tickets: list[int], k: int) -> int:
    ans = 0

    for i, ticket in enumerate(tickets):
      if i <= k:
        ans += min(ticket, tickets[k])
      else:
        ans += min(ticket, tickets[k] - 1)

    return ans
