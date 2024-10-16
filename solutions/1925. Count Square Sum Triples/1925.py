class Solution:
  def countTriples(self, n: int) -> int:
    ans = 0
    squared = set()

    for i in range(1, n + 1):
      squared.add(i * i)

    for a in squared:
      for b in squared:
        if a + b in squared:
          ans += 1

    return ans
