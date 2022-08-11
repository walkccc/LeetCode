class TimeMap:
  def __init__(self):
    self.values = defaultdict(list)
    self.timestamps = defaultdict(list)

  def set(self, key: str, value: str, timestamp: int) -> None:
    self.values[key].append(value)
    self.timestamps[key].append(timestamp)

  def get(self, key: str, timestamp: int) -> str:
    if key not in self.timestamps:
      return ''
    i = bisect.bisect(self.timestamps[key], timestamp)
    return self.values[key][i - 1] if i > 0 else ''
