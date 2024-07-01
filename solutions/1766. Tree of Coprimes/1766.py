class Solution:
  def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
    kMax = 50
    ans = [-1] * len(nums)
    tree = [[] for _ in range(len(nums))]
    # stacks[i] := (node, depth)s of nodes with value i
    stacks = [[] for _ in range(kMax + 1)]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def getAncestor(u: int) -> int:
      maxNode = -1
      maxDepth = -1
      for i, stack in enumerate(stacks):
        if stack and stack[-1][1] > maxDepth and math.gcd(nums[u], i) == 1:
          maxNode, maxDepth = stack[-1]
      return maxNode

    def dfs(u: int, prev: int, depth: int) -> int:
      ans[u] = getAncestor(u)
      stacks[nums[u]].append((u, depth))

      for v in tree[u]:
        if prev != v:
          dfs(v, u, depth + 1)

      stacks[nums[u]].pop()

    dfs(0, -1, 0)
    return ans
