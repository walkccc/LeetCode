from sortedcontainers import SortedList


class MovieRentingSystem:
  def __init__(self, n: int, entries: list[list[int]]):
    self.unrented = collections.defaultdict(
        SortedList)  # {movie: (price, shop)}
    self.shopAndMovieToPrice = {}  # {(shop, movie): price}
    self.rented = SortedList()  # (price, shop, movie)
    for shop, movie, price in entries:
      self.unrented[movie].add((price, shop))
      self.shopAndMovieToPrice[(shop, movie)] = price

  def search(self, movie: int) -> list[int]:
    return [shop for _, shop in self.unrented[movie][:5]]

  def rent(self, shop: int, movie: int) -> None:
    price = self.shopAndMovieToPrice[(shop, movie)]
    self.unrented[movie].remove((price, shop))
    self.rented.add((price, shop, movie))

  def drop(self, shop: int, movie: int) -> None:
    price = self.shopAndMovieToPrice[(shop, movie)]
    self.unrented[movie].add((price, shop))
    self.rented.remove((price, shop, movie))

  def report(self) -> list[list[int]]:
    return [[shop, movie] for _, shop, movie in self.rented[:5]]
