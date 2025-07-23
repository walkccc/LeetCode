class Solution:
  def visibleMountains(self, peaks: list[list[int]]) -> int:
    ans = 0
    maxRightFoot = 0

    peaks.sort(key=lambda x: (x[0] - x[1], -x[0]))

    for i, peak in enumerate(peaks):
      overlapWithNext = i + 1 < len(peaks) and peak == peaks[i + 1]
      currRightFoot = peak[0] + peak[1]
      if currRightFoot > maxRightFoot:
        if not overlapWithNext:
          ans += 1
        maxRightFoot = currRightFoot

    return ans
