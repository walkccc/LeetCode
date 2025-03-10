class TreeAncestor:
  def __init__(self, n: int, parent: list[int]):
    self.maxLevel = n.bit_length()
    # dp[i][j] := node i's 2^j-th ancestor
    self.dp = [[0] * self.maxLevel for _ in range(n)]

    # Node i's 2^0 ancestor is its direct parent
    for i in range(n):
      self.dp[i][0] = parent[i]

    for j in range(1, self.maxLevel):
      for i in range(n):
        if self.dp[i][j - 1] == -1:  # There's no such ancestor
          self.dp[i][j] = -1
        else:  # A(i, 2^j) = A(A(i, 2^{j - 1}), 2^{j - 1})
          self.dp[i][j] = self.dp[self.dp[i][j - 1]][j - 1]

  def getKthAncestor(self, node: int, k: int) -> int:
    for j in range(self.maxLevel):
      if node == -1:
        break
      if k >> j & 1:
        node = self.dp[node][j]
    return node
