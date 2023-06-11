class StringIterator:
  def __init__(self, compressedString: str):
    self.s = compressedString
    self.i = 0    # s's index
    self.num = 0  # currentChar's count
    self.currentChar = ' '

  def next(self) -> str:
    if not self.hasNext():
      return ' '

    if self.num == 0:
      self.currentChar = self.s[self.i]
      self.i += 1
      while self.i < len(self.s) and self.s[self.i].isdigit():
        self.num = self.num * 10 + (ord(self.s[self.i]) - ord('0'))
        self.i += 1

    self.num -= 1
    return self.currentChar

  def hasNext(self) -> bool:
    return self.i < len(self.s) or self.num > 0
