class MagicDictionary:
  def __init__(self):
    self.dict = {}

  def buildDict(self, dict: List[str]) -> None:
    for word in dict:
      for i, c in enumerate(word):
        modifiedWord = word[:i] + '*' + word[i + 1:]
        if modifiedWord not in self.dict:
          self.dict[modifiedWord] = c
        elif self.dict[modifiedWord] != c:
          self.dict[modifiedWord] = '*'

  def search(self, word: str) -> bool:
    for i, c in enumerate(word):
      modifiedWord = word[:i] + '*' + word[i + 1:]
      if modifiedWord in self.dict and self.dict[modifiedWord] != c:
        return True

    return False
