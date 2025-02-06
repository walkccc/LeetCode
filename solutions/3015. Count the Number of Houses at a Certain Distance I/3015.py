class Solution:
  def countOfPairs(self, n: int, x: int, y: int) -> list[int]:
    if x > y:
      x, y = y, x

    def bothInRing(ringLen: int) -> list[int]:
      """
      Returns the contribution from the scenario where two houses are located
      in the ring.
      """
      res = [0] * n
      for k in range(1, (ringLen - 1) // 2 + 1):
        res[k - 1] += ringLen
      if ringLen % 2 == 0:
        res[ringLen // 2 - 1] += ringLen // 2
      return res

    def bothInTheSameLine(lineLen: int) -> list[int]:
      """
      Returns the contribution from the scenario where two houses are either
      located in the left line [1, x) or the right line (y, n].
      """
      res = [0] * n
      for k in range(1, lineLen + 1):
        res[k - 1] += lineLen - k
      return res

    def lineToRing(lineLen: int, ringLen: int) -> list[int]:
      """
      Returns the contribution from the scenario where one house is either
      located in the left line [1, x) or the right line (y, n] and the
      other house is located in the cycle.
      """
      res = [0] * n
      for k in range(1, lineLen + ringLen):
        # min(
        #   at most k - 1 since we need to give 1 to the line,
        #   at most ringLen / 2 since for length > ringLen / 2, it can always be
        #     calculated as ringLen - ringLen / 2
        # )
        maxInRingLen = min(k - 1, ringLen // 2)
        # max(at least 0, at lest k - lineLen)
        minInRingLen = max(0, k - lineLen)
        if minInRingLen <= maxInRingLen:
          # Each ring length contributes 2 to the count due to the split of
          # paths when entering the ring: One path traverses the upper half of
          # the ring, and the other traverses the lower half.
          # This is illustrated as follows:
          #   Path 1: ... -- x -- (upper half of the ring)
          #   Path 2: ... -- x -- (lower half of the ring)
          res[k - 1] += (maxInRingLen - minInRingLen + 1) * 2
          if minInRingLen == 0:
            # Subtract 1 since there's no split.
            res[k - 1] -= 1
          if maxInRingLen * 2 == ringLen:
            # Subtract 1 since the following case only contribute one:
            #   ... -- x -- (upper half of the ring) -- middle point
            #   ... -- x -- (upper half of the ring) -- middle point
            res[k - 1] -= 1
      return res

    def lineToLine(leftLineLen: int, rightLineLen: int) -> list[int]:
      """
      Returns the contribution from the scenario where one house is in the left
      line [1, x) and the other house is in the right line (y, n].
      """
      res = [0] * n
      for k in range(leftLineLen + rightLineLen + 2):
        # min(
        #   at most leftLineLen,
        #   at most k - 1 - (x < y) since we need to give 1 to the right line
        #     and if x < y we need to give another 1 to "x - y".
        # )
        maxInLeft = min(leftLineLen, k - 1 - (x < y))
        # max(at least 1, at least k - rightLineLen - (x < y))
        minInLeft = max(1, k - rightLineLen - (x < y))
        if minInLeft <= maxInLeft:
          res[k - 1] += maxInLeft - minInLeft + 1
      return res

    ringLen = y - x + 1
    leftLineLen = x - 1
    rightLineLen = (n - y)

    ans = [0] * n
    ans = list(map(operator.add, ans, bothInRing(ringLen)))
    ans = list(map(operator.add, ans, bothInTheSameLine(leftLineLen)))
    ans = list(map(operator.add, ans, bothInTheSameLine(rightLineLen)))
    ans = list(map(operator.add, ans, lineToRing(leftLineLen, ringLen)))
    ans = list(map(operator.add, ans, lineToRing(rightLineLen, ringLen)))
    ans = list(map(operator.add, ans, lineToLine(leftLineLen, rightLineLen)))
    return [freq * 2 for freq in ans]
