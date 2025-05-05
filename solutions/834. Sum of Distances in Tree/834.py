class Solution:
  def sumOfDistancesInTree(self, n: int, edges: list[list[int]]) -> list[int]:
    ans = [0] * n
    count = [1] * n
    tree = [set() for _ in range(n)]

    for u, v in edges:
      tree[u].add(v)
      tree[v].add(u)

    def postorder(u: int, prev: int) -> None:
      for v in tree[u]:
        if v == prev:
          continue
        postorder(v, u)
        count[u] += count[v]
        ans[u] += ans[v] + count[v]

    def preorder(u: int, prev: int) -> None:
      for v in tree[u]:
        if v == prev:
          continue
        # count[v] us are 1 step closer from v than prev.
        # (n - count[v]) us are 1 step farther from v than prev.
        ans[v] = ans[u] - count[v] + (n - count[v])
        preorder(v, u)

    postorder(0, -1)
    preorder(0, -1)
    return ans
