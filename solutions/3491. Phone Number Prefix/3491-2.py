class TrieNode:
  def __init__(self):
    self.children: dict[str, TrieNode] = {}
    self.isWord = False


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, number: str) -> None:
    node: TrieNode = self.root
    for d in number:
      node = node.children.setdefault(d, TrieNode())
    node.isWord = True

  def search(self, number: str) -> bool:
    """
    Returns True if the number is a prefix of any number in the trie or any
    number in the trie is a prefix of the number.
    """
    node: TrieNode = self.root
    for d in number:
      if d not in node.children:
        return False
      node = node.children[d]
      if node.isWord:
        return True
    return True  # The number is a prefix of some number in the trie.


class Solution:
  def phonePrefix(self, numbers: list[str]) -> bool:
    trie = Trie()

    for number in numbers:
      if trie.search(number):
        return False
      trie.insert(number)

    return True
