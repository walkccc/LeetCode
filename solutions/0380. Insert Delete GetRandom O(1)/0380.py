class RandomizedSet:
  def __init__(self):
    """
    Initialize your data structure here.
    """
    self.vals = []
    self.valToIndex = defaultdict(int)

  def insert(self, val: int) -> bool:
    """
    Inserts a value to the set. Returns true if the set did not already contain the specified element.
    """
    if val in self.valToIndex:
      return False

    self.valToIndex[val] = len(self.vals)
    self.vals.append(val)
    return True

  def remove(self, val: int) -> bool:
    """
    Removes a value from the set. Returns true if the set contained the specified element.
    """
    if val not in self.valToIndex:
      return False

    index = self.valToIndex[val]
    self.valToIndex[self.vals[-1]] = index
    del self.valToIndex[val]
    self.vals[index] = self.vals[-1]
    self.vals.pop()
    return True

  def getRandom(self) -> int:
    """
    Get a random element from the set.
    """
    index = randint(0, len(self.vals) - 1)
    return self.vals[index]
