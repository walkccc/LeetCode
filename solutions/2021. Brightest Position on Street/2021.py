from sortedcontainers import SortedDict


class Solution:
  def brightestPosition(self, lights: list[list[int]]) -> int:
    ans = math.inf
    maxBrightness = -1
    currBrightness = 0
    line = SortedDict()

    for position, rg in lights:
      start = position - rg
      end = position + rg + 1
      line[start] = line.get(start, 0) + 1
      line[end] = line.get(end, 0) - 1

    for pos, brightness in line.items():
      currBrightness += brightness
      if currBrightness > maxBrightness:
        maxBrightness = currBrightness
        ans = pos

    return ans
