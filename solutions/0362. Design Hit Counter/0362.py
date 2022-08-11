class HitCounter:
  def __init__(self):
    self.timestamps = [0] * 300
    self.hits = [0] * 300

  def hit(self, timestamp: int) -> None:
    i = timestamp % 300

    if self.timestamps[i] == timestamp:
      self.hits[i] += 1
    else:
      self.timestamps[i] = timestamp
      self.hits[i] = 1  # reset hit count to 1

  def getHits(self, timestamp: int) -> int:
    return sum(h for t, h in zip(self.timestamps, self.hits) if timestamp - t < 300)
