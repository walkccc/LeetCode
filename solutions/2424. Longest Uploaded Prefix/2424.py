class LUPrefix:
  def __init__(self, n: int):
    self.seen = set()
    self.longestPrefix = 0

  def upload(self, video: int) -> None:
    self.seen.add(video)
    while self.longestPrefix + 1 in self.seen:
      self.longestPrefix += 1

  def longest(self) -> int:
    return self.longestPrefix
