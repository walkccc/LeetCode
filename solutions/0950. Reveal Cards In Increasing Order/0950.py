class Solution:
  def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
    q = deque()

    for card in sorted(deck)[::-1]:
      q.rotate()
      q.appendleft(card)

    return list(q)
