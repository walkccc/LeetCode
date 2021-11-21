class Trie:
  def __init__(self):
    self.root = {}

  def insert(self, word: str) -> None:
    node = self.root
    for c in word:
      if c not in node:
        node[c] = {}
      node = node[c]
    node['isWord'] = True

  def search(self, word: str) -> bool:
    node = self.find(word)
    return node is not None and 'isWord' in node

  def startsWith(self, prefix: str) -> bool:
    return self.find(prefix) is not None

  def find(self, prefix: str) -> dict:
    node = self.root
    for c in prefix:
      if c not in node:
        return None
      node = node[c]
    return node
