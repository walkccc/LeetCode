class TrieNode:
  def __init__(self):
    self.children: Dict[str, TrieNode] = defaultdict(TrieNode)
    self.depth = 0


class Solution:
  def minimumLengthEncoding(self, words: List[str]) -> int:
    root = TrieNode()
    leaves = []

    def insert(word: str) -> TrieNode:
      node = root
      for c in reversed(word):
        if c not in node.children:
          node.children[c] = TrieNode()
        node = node.children[c]
      node.depth = len(word)
      return node

    for word in set(words):
      leaves.append(insert(word))

    return sum(leaf.depth + 1 for leaf in leaves
               if not len(leaf.children))
