class Solution:
  def largestOverlap(self, img1: list[list[int]], img2: list[list[int]]) -> int:
    kMagic = 100
    ones1 = [(i, j)
             for i, row in enumerate(img1)
             for j, num in enumerate(row)
             if num == 1]
    ones2 = [(i, j)
             for i, row in enumerate(img2)
             for j, num in enumerate(row)
             if num == 1]
    offsetCount = collections.Counter()

    for ax, ay in ones1:
      for bx, by in ones2:
        offsetCount[(ax - bx) * kMagic + (ay - by)] += 1

    return max(offsetCount.values()) if offsetCount else 0
