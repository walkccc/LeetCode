class Solution:
  def componentValue(self, nums: List[int], edges: List[List[int]]) -> int:
    kMax = 1_000_000_000
    n = len(nums)
    summ = sum(nums)
    tree = [[] for _ in range(n)]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def dfs(u: int, target: int, seen: Set[bool]) -> int:
      """
      Returns the sum of the subtree rooted at u substracting the sum of the
      deleted subtrees.
      """
      summ = nums[u]
      seen.add(u)

      for v in tree[u]:
        if v in seen:
          continue
        summ += dfs(v, target, seen)
        if summ > target:
          return kMax

      # Delete the tree that has sum == target.
      if summ == target:
        return 0
      return summ

    for i in range(n, 1, -1):
      # Split the tree into i parts, i.e. delete (i - 1) edges.
      if summ % i == 0 and dfs(0, summ // i, set()) == 0:
        return i - 1

    return 0
