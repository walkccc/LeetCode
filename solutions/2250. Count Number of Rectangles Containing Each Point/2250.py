class Solution:
  def countRectangles(self, rectangles: List[List[int]], points: List[List[int]]) -> List[int]:
    ans = []
    yToXs = [[] for _ in range(101)]

    for l, h in rectangles:
      yToXs[h].append(l)

    for xs in yToXs:
      xs.sort()

    for xi, yi in points:
      count = 0
      for y in range(yi, 101):
        xs = yToXs[y]
        count += len(xs) - bisect.bisect_left(xs, xi)
      ans.append(count)

    return ans
