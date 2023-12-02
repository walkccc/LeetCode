class Solution:
  def maxScore(self, prices: List[int]) -> int:
    groupIdToSum = collections.defaultdict(int)

    for i, price in enumerate(prices):
      groupIdToSum[price - i] += price

    return max(groupIdToSum.values())
