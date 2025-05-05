from sortedcontainers import SortedDict


class Solution:
  def splitPainting(self, segments: list[list[int]]) -> list[list[int]]:
    ans = []
    prevIndex = 0
    runningMix = 0
    line = SortedDict()

    for start, end, color in segments:
      line[start] = line.get(start, 0) + color
      line[end] = line.get(end, 0) - color

    for i, mix in line.items():
      if runningMix > 0:
        ans.append([prevIndex, i, runningMix])
      runningMix += mix
      prevIndex = i

    return ans
