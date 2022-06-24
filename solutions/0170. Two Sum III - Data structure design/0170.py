class TwoSum:
  def __init__(self):
    self.count = Counter()

  def add(self, number: int) -> None:
    self.count[number] += 1

  def find(self, value: int) -> bool:
    for key, freq in self.count.items():
      remain = value - key
      if key == remain and freq > 1:
        return True
      if key != remain and remain in self.count:
        return True

    return False
