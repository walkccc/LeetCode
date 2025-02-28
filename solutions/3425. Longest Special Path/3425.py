class Solution:
  def longestSpecialPath(
      self,
      edges: list[list[int]],
      nums: list[int]
  ) -> list[int]:
    graph = [[] for _ in range(len(nums))]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    def dfs(
        u: int,
        prev: int,
        leftBoundary: int,
        currentDepth: int,
    ) -> None:
      nonlocal maxLength, minNodes
      prevDepth = lastSeenDepth.get(nums[u], 0)
      lastSeenDepth[nums[u]] = currentDepth
      leftBoundary = max(leftBoundary, prevDepth)

      length = prefix[-1] - prefix[leftBoundary]
      nodes = currentDepth - leftBoundary

      if length > maxLength or (length == maxLength and nodes < minNodes):
        maxLength = length
        minNodes = nodes

      for v, w in graph[u]:
        if v == prev:
          continue
        prefix.append(prefix[-1] + w)
        dfs(v, u, leftBoundary, currentDepth + 1)
        prefix.pop()

      lastSeenDepth[nums[u]] = prevDepth

    maxLength = 0
    minNodes = 1
    prefix = [0]
    lastSeenDepth = {}
    dfs(0, -1, 0, 1)
    return [maxLength, minNodes]
