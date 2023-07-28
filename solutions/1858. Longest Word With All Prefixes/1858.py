class Solution:
  def __init__(self):
    self.root = {}

  def longestWord(self, words: List[str]) -> str:
    ans = ''

    for word in words:
      self.insert(word)

    for word in words:
      if not self.allPrefixed(word):
        continue
      if len(ans) < len(word) or (len(ans) == len(word) and ans > word):
        ans = word

    return ans

  def insert(self, word: str) -> None:
    node = self.root
    for c in word:
      if c not in node:
        node[c] = {}
      node = node[c]
    node['isWord'] = True

  def allPrefixed(self, word: str) -> bool:
    node = self.root
    for c in word:
      node = node[c]
      if 'isWord' not in node:
        return False
    return True
