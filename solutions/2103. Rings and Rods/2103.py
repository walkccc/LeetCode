class Solution:
  def countPoints(self, rings: str) -> int:
    colors = [0] * 10

    for c, num in zip(rings[::2], rings[1::2]):
      color = 1 if c == 'R' else 2 if c == 'G' else 4
      colors[int(num)] |= color

    return sum(color == 7 for color in colors)
