class Solution:
  def __init__(self):
    self.root = {}

  def insert(self, word: str) -> None:
    node = self.root
    for c in word:
      if c not in node:
        node[c] = {}
      node = node[c]
    node['word'] = word

  def search(self, word: str) -> str:
    node = self.root
    for c in word:
      if 'word' in node:
        return node['word']
      if c not in node:
        return word
      node = node[c]
    return word

  def replaceWords(self, dictionary: list[str], sentence: str) -> str:
    for word in dictionary:
      self.insert(word)

    words = sentence.split(' ')
    return ' '.join([self.search(word) for word in words])
