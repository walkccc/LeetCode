class WordDictionary:
  def __init__(self):
    self.root = {}

  def addWord(self, word: str) -> None:
    node = self.root
    for c in word:
      if c not in node:
        node[c] = {}
      node = node[c]
    node['isWord'] = True

  def search(self, word: str) -> bool:
    return self.dfs(word, 0, self.root)

  def dfs(self, word: str, s: int, node: dict) -> bool:
    if s == len(word):
      return 'isWord' in node
    if word[s] != '.':
      if word[s] in node:
        return self.dfs(word, s + 1, node[word[s]])
      return False

    for c in string.ascii_lowercase:
      if c in node and self.dfs(word, s + 1, node[c]):
        return True

    return False
