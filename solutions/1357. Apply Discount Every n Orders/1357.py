class Cashier:
  def __init__(
      self,
      n: int,
      discount: int,
      products: list[int],
      prices: list[int],
  ):
    self.n = n
    self.discount = discount
    self.productToPrice = dict(zip(products, prices))
    self.count = 0

  def getBill(self, product: list[int], amount: list[int]) -> float:
    self.count += 1
    total = sum(self.productToPrice[p] * amount[i]
                for i, p in enumerate(product))
    if self.count % self.n == 0:
      return total * (1 - self.discount / 100)
    return total
