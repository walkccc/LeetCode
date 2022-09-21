class Solution:
  def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
    q = deque()

    for card in reversed(sorted(deck)):
      q.rotate()
      q.appendleft(card)

    return list(q)
