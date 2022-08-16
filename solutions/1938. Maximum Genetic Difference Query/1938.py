class TrieNode:
  def __init__(self):
    self.children = [None] * 2
    self.count = 0


class Trie:
  def __init__(self):
    self.root = TrieNode()
    self.kHeight = 17

  def update(self, num: int, val: int) -> None:
    node = self.root
    for i in range(self.kHeight, -1, -1):
      bit = (num >> i) & 1
      if not node.children[bit]:
        node.children[bit] = TrieNode()
      node = node.children[bit]
      node.count += val

  def query(self, num: int) -> int:
    ans = 0
    node = self.root
    for i in range(self.kHeight, -1, -1):
      bit = (num >> i) & 1
      targetBit = bit ^ 1
      if node.children[targetBit] and node.children[targetBit].count > 0:
        ans += 1 << i
        node = node.children[targetBit]
      else:
        node = node.children[targetBit ^ 1]
    return ans


class Solution:
  def maxGeneticDifference(self, parents: List[int], queries: List[List[int]]) -> List[int]:
    n = len(parents)
    ans = [0] * len(queries)
    rootVal = -1
    tree = [[] for _ in range(n)]
    nodeToQueries = defaultdict(list)  # {node: (index, val)}
    trie = Trie()

    for i, parent in enumerate(parents):
      if parent == -1:
        rootVal = i
      else:
        tree[parent].append(i)

    for i, (node, val) in enumerate(queries):
      nodeToQueries[node].append((i, val))

    def dfs(node: int) -> None:
      trie.update(node, 1)

      # answer queries for node
      for i, val in nodeToQueries[node]:
        ans[i] = trie.query(val)

      for child in tree[node]:
        dfs(child)

      trie.update(node, -1)

    dfs(rootVal)
    return ans
