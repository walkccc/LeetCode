class Pair:
  def __init__(self, x: int, y: int):
    self.x = x
    self.y = y

  def __iter__(self):
    yield self.x
    yield self.y


class IndexAndQuery:
  def __init__(self, index: int, minX: int, minY: int):
    self.index = index
    self.minX = minX
    self.minY = minY

  def __iter__(self):
    yield self.index
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

    i = 0
    for index, minX, minY in indexAndQueries:
      while i < len(pairs) and pairs[i].x >= minX:
        x, y = pairs[i]
        while stack and x + y >= stack[-1][1]:
          stack.pop()
        if not stack or y > stack[-1][0]:
          stack.append((y, x + y))
        i += 1
      j = self._firstGreaterEqual(stack, minY)
      ans[index] = -1 if j == len(stack) else stack[j][1]

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
