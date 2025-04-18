class TrieNode:
  def __init__(self):
    self.children: list[TrieNode | None] = [None] * 2


class BitTrie:
  def __init__(self, maxBit: int):
    self.maxBit = maxBit
    self.root = TrieNode()

  def insert(self, num: int) -> None:
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = num >> i & 1
      if not node.children[bit]:
        node.children[bit] = TrieNode()
      node = node.children[bit]

  def getMaxXor(self, num: int) -> int:
    maxXor = 0
    node = self.root
    for i in range(self.maxBit, -1, -1):
      bit = num >> i & 1
      toggleBit = bit ^ 1
      if node.children[toggleBit]:
        maxXor = maxXor | 1 << i
        node = node.children[toggleBit]
      elif node.children[bit]:
        node = node.children[bit]
      else:  # There's nothing in the Bit Trie.
        return 0
    return maxXor


class Solution:
  def maxXor(self, n: int, edges: list[list[int]], values: list[int]) -> int:
    ans = 0
    tree = [[] for _ in range(n)]
    treeSums = [0] * n

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    # Gets the tree sum rooted at node u.
    def getTreeSum(u: int, prev: int) -> int:
      treeSum = values[u] + sum(getTreeSum(v, u) for v in tree[u] if v != prev)
      treeSums[u] = treeSum
      return treeSum

    def dfs(u: int, prev: int, bitTrie: BitTrie) -> None:
      nonlocal ans
      for v in tree[u]:
        if v == prev:
          continue
        # Preorder to get the ans.
        ans = max(ans, bitTrie.getMaxXor(treeSums[v]))
        # Recursively call on the subtree rooted at node v.
        dfs(v, u, bitTrie)
        # Postorder to insert the tree sum rooted at node v.
        bitTrie.insert(treeSums[v])

    getTreeSum(0, -1)
    maxBit = int(math.log2(max(treeSums[1:])))
    # Similar to 421. Maximum XOR of Two Numbers in an Array
    dfs(0, -1, BitTrie(maxBit))
    return ans
