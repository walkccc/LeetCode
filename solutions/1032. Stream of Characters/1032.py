from dataclasses import dataclass


@dataclass
class TrieNode:
  children: dict[str, TrieNode]
  isWord: bool


class StreamChecker:
  def __init__(self, words: list[str]):
    self.root = TrieNode()
    self.letters = []

    for word in words:
      self._insert(word)

  def query(self, letter: str) -> bool:
    self.letters.append(letter)
    node = self.root
    for c in reversed(self.letters):
      if c not in node.children:
        return False
      node = node.children[c]
      if node.isWord:
        return True
    return False

  def _insert(self, word: str) -> None:
    node = self.root
    for c in reversed(word):
      node = node.children.setdefault(c, TrieNode())
    node.isWord = True
