class Solution:
  def smallestMissingValueSubtree(self, parents: List[int], nums: List[int]) -> List[int]:
    n = len(parents)
    ans = [1] * n
    tree = [[] for _ in range(n)]
    seen = set()
    minMiss = 1

    for i in range(1, n):
      tree[parents[i]].append(i)

    def getNode(nums: List[int]) -> int:
      for i, num in enumerate(nums):
        if num == 1:
          return i
      return -1

    nodeThatsOne = getNode(nums)
    if nodeThatsOne == -1:
      return ans

    u = nodeThatsOne
    prev = -1  # the u that just handled

    def dfs(u: int) -> None:
      seen.add(nums[u])
      for v in tree[u]:
        dfs(v)

    # Upward from the `nodeThatsOne` to the root `u`.
    while u != -1:
      for v in tree[u]:
        if v == prev:
          continue
        dfs(v)
      seen.add(nums[u])
      while minMiss in seen:
        minMiss += 1
      ans[u] = minMiss
      prev = u
      u = parents[u]

    return ans
