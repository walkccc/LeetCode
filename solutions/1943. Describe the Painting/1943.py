from sortedcontainers import SortedDict


class Solution:
  def splitPainting(self, segments: list[list[int]]) -> list[list[int]]:
    ans = []
    prevIndex = 0
    runningMix = 0
    timeline = SortedDict()

    for start, end, color in segments:
      timeline[start] = timeline.get(start, 0) + color
      timeline[end] = timeline.get(end, 0) - color

    for i, mix in timeline.items():
      if runningMix > 0:
        ans.append([prevIndex, i, runningMix])
      runningMix += mix
      prevIndex = i

    return ans
