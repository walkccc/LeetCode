class MagicDictionary:
  def __init__(self):
    self.dict = {}

  def buildDict(self, dictionary: List[str]) -> None:
    for word in dictionary:
      for i, c in enumerate(word):
        replaced = self._getReplaced(word, i)
        self.dict[replaced] = '*' if replaced in self.dict else c

  def search(self, searchWord: str) -> bool:
    for i, c in enumerate(searchWord):
      replaced = self._getReplaced(searchWord, i)
      if self.dict.get(replaced, c) != c:
        return True
    return False

  def _getReplaced(self, s: str, i: int) -> str:
    return s[:i] + '*' + s[i + 1:]
