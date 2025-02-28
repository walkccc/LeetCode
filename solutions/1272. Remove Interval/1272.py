class Solution:
  def removeInterval(self, intervals: list[list[int]],
                     toBeRemoved: list[int]) -> list[list[int]]:
    ans = []

    for a, b in intervals:
      if a >= toBeRemoved[1] or b <= toBeRemoved[0]:
        ans.append([a, b])
      else:  # a < toBeRemoved[1] and b > toBeRemoved[0]
        if a < toBeRemoved[0]:
          ans.append([a, toBeRemoved[0]])
        if b > toBeRemoved[1]:
          ans.append([toBeRemoved[1], b])

    return ans
