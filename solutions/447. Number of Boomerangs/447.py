class Solution:
  def numberOfBoomerangs(self, points: list[list[int]]) -> int:
    ans = 0

    for x1, y1 in points:
      count = collections.Counter()
      for x2, y2 in points:
        ans += 2 * count[(x1 - x2)**2 + (y1 - y2)**2]
        count[(x1 - x2)**2 + (y1 - y2)**2] += 1

    return ans
