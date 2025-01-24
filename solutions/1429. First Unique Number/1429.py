class FirstUnique:
  def __init__(self, nums: list[int]):
    self.seen = set()
    self.unique = {}
    for num in nums:
      self.add(num)

  def showFirstUnique(self) -> int:
    return next(iter(self.unique), -1)

  def add(self, value: int) -> None:
    if value not in self.seen:
      self.seen.add(value)
      self.unique[value] = 1
    elif value in self.unique:
      # We have added this value before, and this is the second time we're
      # adding it. So, erase the value from `unique`.
      self.unique.pop(value)
