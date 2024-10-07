class Solution:
  def maxIntersectionCount(self, y: list[int]) -> int:
    ans = 0
    intersectionCount = 0
    line = collections.Counter()

    for i, (a, b) in enumerate(itertools.pairwise(y)):
      start = 2 * a
      end = 2 * b + (0 if i == len(y) - 2 else -1 if b > a else 1)
      line[min(start, end)] += 1
      line[max(start, end) + 1] -= 1

    for count in sorted(line):
      intersectionCount += line[count]
      ans = max(ans, intersectionCount)

    return ans
