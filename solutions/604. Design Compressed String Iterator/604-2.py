class StringIterator:
  def __init__(self, compressedString: str):
    self.q = collections.deque()  # (currentChar, num)

    i = 0  # compressedString's index
    while i < len(compressedString):
      c = compressedString[i]
      i += 1
      num = 0
      while i < len(compressedString) and compressedString[i].isdigit():
        num = num * 10 + (ord(compressedString[i]) - ord('0'))
        i += 1
      self.q.append((c, num))

  def next(self) -> str:
    if not self.hasNext():
      return ' '

    c, num = self.q.popleft()
    if num > 1:
      self.q.appendleft((c, num - 1))
    return c

  def hasNext(self) -> bool:
    return self.q
