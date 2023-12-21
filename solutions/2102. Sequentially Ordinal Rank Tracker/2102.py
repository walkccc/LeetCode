class Location:
  def __init__(self, name: str, score: int):
    self.name = name
    self.score = score

  def __lt__(self, location):
    if self.score == location.score:
      return self.name > location.name
    return self.score < location.score


class SORTracker:
  def __init__(self):
    self.l = []
    self.r = []
    self.k = 0  the number of times get() called

  def add(self, name: str, score: int) -> None:
    heapq.heappush(self.l, Location(name, score))
    if len(self.l) > self.k + 1:
      location = heapq.heappop(self.l)
      heapq.heappush(self.r, (-location.score, location.name))

  def get(self) -> str:
    name = self.l[0].name
    if self.r:
      topScore, topName = heapq.heappop(self.r)
      heapq.heappush(self.l, Location(topName, -topScore))
    self.k += 1
    return name
