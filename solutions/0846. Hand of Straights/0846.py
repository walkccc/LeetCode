class Solution:
  def isNStraightHand(self, hand: List[int], W: int) -> bool:
    count = Counter(hand)

    for start in sorted(count):
      value = count[start]
      if value > 0:
        for i in range(start, start + W):
          count[i] -= value
          if count[i] < 0:
            return False

    return True
