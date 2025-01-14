class Allocator:
  def __init__(self, n: int):
    self.memory = [0] * n
    self.mIDToIndices = [[] for _ in range(1001)]

  def allocate(self, size: int, mID: int) -> int:
    consecutiveFree = 0
    for i, m in enumerate(self.memory):
      consecutiveFree = consecutiveFree + 1 if m == 0 else 0
      if consecutiveFree == size:
        for j in range(i - consecutiveFree + 1, i + 1):
          self.memory[j] = mID
          self.mIDToIndices[mID].append(j)
        return i - consecutiveFree + 1
    return -1

  def free(self, mID: int) -> int:
    indices = self.mIDToIndices[mID]
    freedUnits = len(indices)
    for index in indices:
      self.memory[index] = 0
    indices.clear()
    return freedUnits
