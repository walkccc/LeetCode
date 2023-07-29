class RandomizedCollection:
  def __init__(self):
    """
    Initialize your data structure here.
    """
    self.vals = []
    self.valToIndices = collections.defaultdict(list)

  def insert(self, val: int) -> bool:
    """
    Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
    """
    self.valToIndices[val].append(len(self.vals))
    self.vals.append([val, len(self.valToIndices[val]) - 1])
    return len(self.valToIndices[val]) == 1

  def remove(self, val: int) -> bool:
    """
    Removes a value from the collection. Returns true if the collection contained the specified element.
    """
    if val not in self.valToIndices or self.valToIndices[val] == []:
      return False

    index = self.valToIndices[val][-1]
    self.valToIndices[self.vals[-1][0]][self.vals[-1][1]] = index
    self.valToIndices[val].pop()
    self.vals[index] = self.vals[-1]
    self.vals.pop()
    return True

  def getRandom(self) -> int:
    """
    Get a random element from the collection.
    """
    index = random.randint(0, len(self.vals) - 1)
    return self.vals[index][0]
