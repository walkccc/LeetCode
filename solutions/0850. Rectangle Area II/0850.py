class Solution:
  def rectangleArea(self, rectangles: List[List[int]]) -> int:
    events = []

    for x1, y1, x2, y2 in rectangles:
      events.append((x1, y1, y2, 's'))
      events.append((x2, y1, y2, 'e'))

    events.sort(key=lambda x: x[0])

    ans = 0
    prevX = 0
    yPairs = []

    def getHeight(yPairs: List[Tuple[int, int]]) -> int:
      height = 0
      prevY = 0

      for y1, y2 in yPairs:
        prevY = max(prevY, y1)
        if y2 > prevY:
          height += y2 - prevY
          prevY = y2

      return height

    for currX, y1, y2, type in events:
      if currX > prevX:
        width = currX - prevX
        ans += width * getHeight(yPairs)
        prevX = currX
      if type == 's':
        yPairs.append((y1, y2))
        yPairs.sort()
      else:  # type == 'e'
        yPairs.remove((y1, y2))

    return ans % (10**9 + 7)
