class ValidWordAbbr:
  def __init__(self, dictionary: List[str]):
    self.dict = set(dictionary)
    # T := unique, F := not unique
    self.abbrUnique = {}

    for word in self.dict:
      abbr = self._getAbbr(word)
      self.abbrUnique[abbr] = abbr not in self.abbrUnique

  def isUnique(self, word: str) -> bool:
    abbr = self._getAbbr(word)
    return abbr not in self.abbrUnique or self.abbrUnique[abbr] and word in self.dict

  def _getAbbr(self, s: str) -> str:
    n = len(s)
    if n <= 2:
      return s
    return s[0] + str(n - 2) + s[-1]
