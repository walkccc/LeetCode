class Solution:
  def queryResults(self, limit: int, queries: list[list[int]]) -> list[int]:
    ans = []
    ballToColor = {}
    colorCount = collections.Counter()

    for ball, color in queries:
      if ball in ballToColor:
        prevColor = ballToColor[ball]
        colorCount[prevColor] -= 1
        if colorCount[prevColor] == 0:
          del colorCount[prevColor]
      ballToColor[ball] = color
      colorCount[color] += 1
      ans.append(len(colorCount))

    return ans
