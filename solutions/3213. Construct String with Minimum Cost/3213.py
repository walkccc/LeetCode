class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.cost = math.inf


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word: str, cost: int) -> None:
    """Inserts a word with a cost."""
    node: TrieNode = self.root
    for c in word:
      node = node.children.setdefault(c, TrieNode())
    node.cost = min(node.cost, cost)

  @functools.lru_cache(None)
  def search(self, word: str, i: int) -> int:
    """Returns the minimum cost to construct s[i:]."""
    if i == len(word):
      return 0
    cost = math.inf
    node = self.root
    for i in range(i, len(word)):
      if word[i] not in node.children:
        break
      node = node.children[word[i]]
      if node.cost != math.inf:
        childCost = self.search(word, i + 1)
        if childCost != math.inf:
          cost = min(cost, node.cost + childCost)
    return cost


class Solution:
  def minimumCost(self, target: str, words: list[str], costs: list[int]) -> int:
    trie = Trie()

    for word, cost in zip(words, costs):
      trie.insert(word, cost)

    ans = trie.search(target, 0)
    return -1 if ans == math.inf else ans
