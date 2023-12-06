class Solution:
  def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
    dq = collections.deque()

    for card in reversed(sorted(deck)):
      dq.rotate()
      dq.appendleft(card)

    return list(dq)
