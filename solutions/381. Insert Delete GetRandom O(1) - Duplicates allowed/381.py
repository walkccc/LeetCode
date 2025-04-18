class RandomizedCollection:
  def __init__(self):
    self.vals = []
    self.valToIndices = collections.defaultdict(list)

  def insert(self, val: int) -> bool:
    self.valToIndices[val].append(len(self.vals))
    self.vals.append([val, len(self.valToIndices[val]) - 1])
    return len(self.valToIndices[val]) == 1

  def remove(self, val: int) -> bool:
    if val not in self.valToIndices or self.valToIndices[val] == []:
      return False

    index = self.valToIndices[val][-1]
    self.valToIndices[self.vals[-1][0]][self.vals[-1][1]] = index
    self.valToIndices[val].pop()
    self.vals[index] = self.vals[-1]
    self.vals.pop()
    return True

  def getRandom(self) -> int:
    index = random.randint(0, len(self.vals) - 1)
    return self.vals[index][0]
