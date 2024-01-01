class IndexedQuery:
  def __init__(self, queryIndex: int, a: int, b: int):
    self.queryIndex = queryIndex
    self.a = a  # Alice's index
    self.b = b  # Bob's index

  def __iter__(self):
    yield self.queryIndex
    yield self.a
    yield self.b


class Solution:
  # Similar to 2736. Maximum Sum Queries
  def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
    ans = [-1] * len(queries)
    # Store indices (heightsIndex) of heights with heights[heightsIndex] in
    # descending order.
    stack = []

    # Iterate through queries and heights simultaneously.
    heightsIndex = len(heights) - 1
    for queryIndex, a, b in sorted([IndexedQuery(i, min(a, b), max(a, b))
                                    for i, (a, b) in enumerate(queries)],
                                   key=lambda iq: -iq.b):
      if a == b or heights[a] < heights[b]:
        # 1. Alice and Bob are already in the same index (a == b) or
        # 2. Alice can jump from a -> b (heights[a] < heights[b]).
        ans[queryIndex] = b
      else:
        # Now, a < b and heights[a] >= heights[b].
        # Gradually add heights with an index > b to the monotonic stack.
        while heightsIndex > b:
          # heights[heightsIndex] is a better candidate, given that
          # heightsIndex is smaller than the indices in the stack and
          # heights[heightsIndex] is larger or equal to the heights mapped in
          # the stack.
          while stack and heights[stack[-1]] <= heights[heightsIndex]:
            stack.pop()
          stack.append(heightsIndex)
          heightsIndex -= 1
        # Binary search to find the smallest index j such that j > b and
        # heights[j] > heights[a], thereby ensuring heights[j] > heights[b].
        j = self._lastGreater(stack, a, heights)
        if j != -1:
          ans[queryIndex] = stack[j]

    return ans

  def _lastGreater(self, A: List[int], target: int, heights: List[int]):
    """
    Returns the last index i in A s.t. heights[A.get(i)] is > heights[target].
    """
    l = -1
    r = len(A) - 1
    while l < r:
      m = (l + r + 1) // 2
      if heights[A[m]] > heights[target]:
        l = m
      else:
        r = m - 1
    return l
