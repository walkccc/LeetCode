class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.isWord = False
    self.length = math.inf
    self.index = -1


class Solution:
  def stringIndices(
      self,
      wordsContainer: list[str],
      wordsQuery: list[str],
  ) -> list[int]:
    ans = []
    root = TrieNode()
    minIndex = min(enumerate(wordsContainer), key=lambda x: len(x[1]))[0]

    def insert(word: str, index: int) -> None:
      node = root
      for c in reversed(word):
        node = node.children.setdefault(c, TrieNode())
        if node.length > len(word):
          node.length = len(word)
          node.index = index

    def search(word: str) -> int:
      node = root
      for c in reversed(word):
        if c not in node.children:
          return node.index
        node = node.children[c]
      return node.index

    for i, word in enumerate(wordsContainer):
      insert(word, i)

    for query in wordsQuery:
      index = search(query)
      ans.append(minIndex if index == -1 else index)

    return ans
