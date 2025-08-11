class Solution:
  def maximizeSquareArea(
      self,
      m: int,
      n: int,
      hFences: list[int],
      vFences: list[int],
  ) -> int:
    hFences = sorted(hFences + [1, m])
    vFences = sorted(vFences + [1, n])
    hGaps = {hFences[i] - hFences[j]
             for i in range(len(hFences))
             for j in range(i)}
    vGaps = {vFences[i] - vFences[j]
             for i in range(len(vFences))
             for j in range(i)}
    maxGap = next((hGap
                  for hGap in sorted(hGaps, reverse=True)
                  if hGap in vGaps), -1)
    return -1 if maxGap == -1 else maxGap**2 % (10**9 + 7)
