class Solution:
  def pourWater(self, heights: list[int], volume: int, k: int) -> list[int]:
    i = k

    while volume > 0:
      volume -= 1
      while i > 0 and heights[i] >= heights[i - 1]:
        i -= 1
      while i + 1 < len(heights) and heights[i] >= heights[i + 1]:
        i += 1
      while i > k and heights[i] == heights[i - 1]:
        i -= 1
      heights[i] += 1

    return heights
