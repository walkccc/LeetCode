class ProductOfNumbers:
  def __init__(self):
    self.prefix = [1]

  def add(self, num: int) -> None:
    if num == 0:
      self.prefix = [1]
    else:
      self.prefix.append(self.prefix[-1] * num)

  def getProduct(self, k: int) -> int:
    return 0 if k >= len(self.prefix) else self.prefix[-1] // self.prefix[len(self.prefix) - k - 1]
