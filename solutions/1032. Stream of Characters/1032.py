class StreamChecker:
  def __init__(self, words: List[str]):
    self.root = {}
    self.letters = ''

    for word in words:
      self.insert(word)

  def query(self, letter: str) -> bool:
    self.letters += letter
    node = self.root

    for c in self.letters[::-1]:
      if c not in node:
        return False
      node = node[c]
      if 'isWord' in node:
        return True

    return False

  def insert(self, word: str) -> None:
    node = self.root
    for c in word[::-1]:
      if c not in node:
        node[c] = {}
      node = node[c]
    node['isWord'] = True
