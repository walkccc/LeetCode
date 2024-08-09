from sortedcontainers import SortedDict


class StockPrice:
  def __init__(self):
    self.timestampToPrice = SortedDict()
    self.pricesCount = SortedDict()

  def update(self, timestamp: int, price: int) -> None:
    if timestamp in self.timestampToPrice:
      prevPrice = self.timestampToPrice[timestamp]
      self.pricesCount[prevPrice] -= 1
      if self.pricesCount[prevPrice] == 0:
        del self.pricesCount[prevPrice]
    self.timestampToPrice[timestamp] = price
    self.pricesCount[price] = self.pricesCount.get(price, 0) + 1

  def current(self) -> int:
    return self.timestampToPrice.peekitem(-1)[1]

  def maximum(self) -> int:
    return self.pricesCount.peekitem(-1)[0]

  def minimum(self) -> int:
    return self.pricesCount.peekitem(0)[0]
