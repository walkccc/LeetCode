class Solution:
  def __init__(self, n: int, blacklist: list[int]):
    self.validRange = n - len(blacklist)
    self.dict = {}

    maxAvailable = n - 1

    for b in blacklist:
      self.dict[b] = -1

    for b in blacklist:
      if b < self.validRange:
        # Find the slot that haven't been used.
        while maxAvailable in self.dict:
          maxAvailable -= 1
        self.dict[b] = maxAvailable
        maxAvailable -= 1

  def pick(self) -> int:
    value = random.randint(0, self.validRange - 1)

    if value in self.dict:
      return self.dict[value]

    return value
