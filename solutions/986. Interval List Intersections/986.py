class Solution:
  def intervalIntersection(self, firstList: list[list[int]],
                           secondList: list[list[int]]) -> list[list[int]]:
    ans = []
    i = 0
    j = 0

    while i < len(firstList) and j < len(secondList):
      # lo := the start of the intersection
      # hi := the end of the intersection
      lo = max(firstlist[i][0], secondlist[j][0])
      hi = min(firstlist[i][1], secondlist[j][1])
      if lo <= hi:
        ans.append([lo, hi])
      if firstlist[i][1] < secondlist[j][1]:
        i += 1
      else:
        j += 1

    return ans
