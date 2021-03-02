class TimeMap:
  def __init__(self):
    self.timestamps = defaultdict(list)
    self.values = defaultdict(list)

  def set(self, key: str, value: str, timestamp: int) -> None:
    self.timestamps[key].append(timestamp)
    self.values[key].append(value)

  def get(self, key: str, timestamp: int) -> str:
    i = bisect.bisect(self.timestamps[key], timestamp)
    return self.values[key][i - 1] if i > 0 else ''
