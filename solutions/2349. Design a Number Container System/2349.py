from sortedcontainers import SortedSet


class NumberContainers:
  def __init__(self):
    self.numberToIndices = collections.defaultdict(SortedSet)
    self.indexToNumber = {}

  def change(self, index: int, number: int) -> None:
    if index in self.indexToNumber:
      originalNumber = self.indexToNumber[index]
      self.numberToIndices[originalNumber].remove(index)
      if len(self.numberToIndices[originalNumber]) == 0:
        del self.numberToIndices[originalNumber]
    self.indexToNumber[index] = number
    self.numberToIndices[number].add(index)

  def find(self, number: int) -> int:
    if number in self.numberToIndices:
      return self.numberToIndices[number][0]
    return -1
