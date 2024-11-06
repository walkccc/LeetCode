class RandomizedSet:
  def __init__(self):
    self.vals = []
    self.valToIndex = collections.defaultdict(int)  # {val: index in vals}

  def insert(self, val: int) -> bool:
    if val in self.valToIndex:
      return False
    self.valToIndex[val] = len(self.vals)
    self.vals.append(val)
    return True

  def remove(self, val: int) -> bool:
    if val not in self.valToIndex:
      return False
    index = self.valToIndex[val]
    # The order of the following two lines is important when vals.size() == 1.
    self.valToIndex[self.vals[-1]] = index
    del self.valToIndex[val]
    self.vals[index] = self.vals[-1]
    self.vals.pop()
    return True

  def getRandom(self) -> int:
    index = random.randint(0, len(self.vals) - 1)
    return self.vals[index]
