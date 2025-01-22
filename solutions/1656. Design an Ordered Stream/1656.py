class OrderedStream:
  def __init__(self, n: int):
    self.values = [''] * n
    self.i = 0  # self.values' index (0-indexed)

  def insert(self, idKey: int, value: str) -> list[str]:
    idKey -= 1  # Converts to 0-indexed.
    self.values[idKey] = value
    if idKey > self.i:
      return []
    while self.i < len(self.values) and self.values[self.i]:
      self.i += 1
    return self.values[idKey:self.i]
