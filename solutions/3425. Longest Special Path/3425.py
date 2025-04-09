class Solution:
  def longestSpecialPath(
      self,
      edges: list[list[int]],
      nums: list[int]
  ) -> list[int]:
    maxLength = 0
    minNodes = 1
    graph = [[] for _ in range(len(nums))]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    prefix = [0]
    lastSeenDepth = {}

    def dfs(
        u: int,
        prev: int,
        leftBoundary: int,
    ) -> None:
      nonlocal maxLength, minNodes
      prevDepth = lastSeenDepth.get(nums[u], 0)
      lastSeenDepth[nums[u]] = len(prefix)
      leftBoundary = max(leftBoundary, prevDepth)

      length = prefix[-1] - prefix[leftBoundary]
      nodes = len(prefix) - leftBoundary
      if length > maxLength or (length == maxLength and nodes < minNodes):
        maxLength = length
        minNodes = nodes

      for v, w in graph[u]:
        if v == prev:
          continue
        prefix.append(prefix[-1] + w)
        dfs(v, u, leftBoundary)
        prefix.pop()

      lastSeenDepth[nums[u]] = prevDepth

    dfs(0, -1, leftBoundary=0)
    return [maxLength, minNodes]
