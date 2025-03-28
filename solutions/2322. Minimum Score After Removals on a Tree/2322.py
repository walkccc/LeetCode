class Solution:
  def minimumScore(self, nums: list[int], edges: list[list[int]]) -> int:
    n = len(nums)
    xors = functools.reduce(operator.xor, nums)
    subXors = nums[:]
    tree = [[] for _ in range(n)]
    children = [{i} for i in range(n)]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def dfs(u: int, prev: int) -> tuple[int, set[int]]:
      for v in tree[u]:
        if v == prev:
          continue
        vXor, vChildren = dfs(v, u)
        subXors[u] ^= vXor
        children[u] |= vChildren
      return subXors[u], children[u]

    dfs(0, -1)

    ans = math.inf
    for i in range(len(edges)):
      a, b = edges[i]
      if b in children[a]:
        a, b = b, a
      for j in range(i):
        c, d = edges[j]
        if d in children[c]:
          c, d = d, c

        if c in children[a] and a != c:
          cands = [subXors[c], subXors[a] ^ subXors[c], xors ^ subXors[a]]
        elif a in children[c] and a != c:
          cands = [subXors[a], subXors[c] ^ subXors[a], xors ^ subXors[c]]
        else:
          cands = [subXors[a], subXors[c], xors ^ subXors[a] ^ subXors[c]]
        ans = min(ans, max(cands) - min(cands))

    return ans
