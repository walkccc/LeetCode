class Pair:
  def __init__(self, x: int, y: int):
    self.x = x
    self.y = y

  def __iter__(self):
    yield self.x
    yield self.y


class IndexAndQuery:
  def __init__(self, i: int, minX: int, minY: int):
    self.i = i
    self.minX = minX
    self.minY = minY

  def __iter__(self):
    yield self.i
    yield self.minX
    yield self.minY


class Solution:
  def maximumSumQueries(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
    pairs = sorted([Pair(nums1[i], nums2[i])
                   for i in range(len(nums1))], key=lambda p: p.x, reverse=True)
    indexAndQueries = sorted([IndexAndQuery(i, query[0], query[1])
                              for i, query in enumerate(queries)],
                             key=lambda iq: iq.minX, reverse=True)
    ans = [0] * len(queries)
    stack = []  # [(y, x + y)]

    pairsIndex = 0
    for i, minX, minY in indexAndQueries:
      while pairsIndex < len(pairs) and pairs[pairsIndex].x >= minX:
        # x + y is a better candidate. Given that x is decreasing, the
        # condition "x + y >= stack[-1][1]" suggests that y is relatively
        # larger, thereby making it a better candidate.
        x, y = pairs[pairsIndex]
        while stack and x + y >= stack[-1][1]:
          stack.pop()
        if not stack or y > stack[-1][0]:
          stack.append((y, x + y))
        pairsIndex += 1
      j = self._firstGreaterEqual(stack, minY)
      ans[i] = -1 if j == len(stack) else stack[j][1]

    return ans

  def _firstGreaterEqual(self, A: List[Tuple[int, int]], target: int) -> int:
    l = 0
    r = len(A)
    while l < r:
      m = (l + r) // 2
      if A[m][0] >= target:
        r = m
      else:
        l = m + 1
    return l
