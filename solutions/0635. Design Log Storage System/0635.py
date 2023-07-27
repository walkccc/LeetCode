class LogSystem:
  def __init__(self):
    self.granularityToIndices = {'Year': 4, 'Month': 7, 'Day': 10,
                                 'Hour': 13, 'Minute': 16, 'Second': 19}
    self.idAndTimestamps = []

  def put(self, id: int, timestamp: str) -> None:
    self.idAndTimestamps.append((id, timestamp))

  def retrieve(self, start: str, end: str, granularity: str) -> List[int]:
    index = self.granularityToIndices[granularity]
    s = start[:index]
    e = end[:index]
    return [id for id, timestamp in self.idAndTimestamps
            if s <= timestamp[:index] <= e]
