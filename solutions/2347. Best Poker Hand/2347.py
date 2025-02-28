class Solution:
  def bestHand(self, ranks: list[int], suits: list[str]) -> str:
    if all(suit == suits[0] for suit in suits):
      return 'Flush'

    match max(Counter(ranks).values()):
      case 5 | 4 | 3:
        return 'Three of a Kind'
      case 2:
        return 'Pair'
      case _:
        return 'High Card'
