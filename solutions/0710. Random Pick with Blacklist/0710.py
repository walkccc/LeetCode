class Solution:
  def __init__(self, N: int, blacklist: List[int]):
    self.validRange = N - len(blacklist)
    self.dict = {}

    for b in blacklist:
      self.dict[b] = -1

    for b in blacklist:
      if b < self.validRange:
        while N - 1 in self.dict:
          N -= 1
        self.dict[b] = N - 1
        N -= 1

  def pick(self) -> int:
    value = randint(0, self.validRange - 1)

    if value in self.dict:
      return self.dict[value]

    return value
