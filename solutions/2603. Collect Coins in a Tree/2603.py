class Solution:
  def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
    n = len(coins)
    tree = [set() for _ in range(n)]
    leavesToBeRemoved = collections.deque()

    for u, v in edges:
      tree[u].add(v)
      tree[v].add(u)

    for u in range(n):
      # Remove the leaves that don't have coins.
      while len(tree[u]) == 1 and coins[u] == 0:
        v = tree[u].pop()
        tree[v].remove(u)
        u = v  # Walk up to its parent.
      # After trimming leaves without coins, leaves with coins may satisfy
      # `leavesToBeRemoved`.
      if len(tree[u]) == 1:  # coins[u] must be 1.
        leavesToBeRemoved.append(u)

    # Remove each remaining leaf node and its parent. The remaining nodes are
    # the ones that must be visited.
    for _ in range(2):
      for _ in range(len(leavesToBeRemoved)):
        u = leavesToBeRemoved.popleft()
        if tree[u]:
          v = tree[u].pop()
          tree[v].remove(u)
          if len(tree[v]) == 1:  # It's a leaf.
            leavesToBeRemoved.append(v)

    return sum(len(children) for children in tree)
