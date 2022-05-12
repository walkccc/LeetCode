class Solution:
  def minimumCardPickup(self, cards: List[int]) -> int:
    ans = math.inf
    lastOccurrence = {}

    for i, card in enumerate(cards):
      if card in lastOccurrence:
        ans = min(ans, i - lastOccurrence[card] + 1)
      lastOccurrence[card] = i

    return -1 if ans == math.inf else ans
