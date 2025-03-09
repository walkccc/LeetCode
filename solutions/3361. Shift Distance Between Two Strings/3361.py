class Solution:
  def shiftDistance(
      self,
      s: str,
      t: str,
      nextCost: list[int],
      previousCost: list[int]
  ) -> int:
    ans = 0
    # prev[i][j]: the prev cost to shift from ('a' + i) to ('a' + j)
    prev = [[0] * 26 for _ in range(26)]
    # next[i][j]: the next cost to shift from ('a' + i) to ('a' + j)
    next = [[0] * 26 for _ in range(26)]

    for i in range(26):
      cost = 0
      for j in range(26):
        next[i][(i + j) % 26] = cost
        cost += nextCost[(i + j) % 26]

    for i in range(26):
      cost = 0
      for j in range(26):
        prev[i][(i - j + 26) % 26] = cost
        cost += previousCost[(i - j + 26) % 26]

    for a, b in zip(s, t):
      i = ord(a) - ord('a')
      j = ord(b) - ord('a')
      ans += min(next[i][j], prev[i][j])

    return ans
