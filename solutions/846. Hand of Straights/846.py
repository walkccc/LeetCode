class Solution:
  def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
    count = collections.Counter(hand)

    for start in sorted(count):
      value = count[start]
      if value > 0:
        for i in range(start, start + groupSize):
          count[i] -= value
          if count[i] < 0:
            return False

    return True
