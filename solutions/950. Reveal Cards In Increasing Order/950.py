class Solution:
  def deckRevealedIncreasing(self, deck: list[int]) -> list[int]:
    dq = collections.deque()

    for card in reversed(sorted(deck)):
      dq.rotate()
      dq.appendleft(card)

    return list(dq)
