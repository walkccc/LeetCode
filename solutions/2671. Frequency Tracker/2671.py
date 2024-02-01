class FrequencyTracker:
  def __init__(self):
    self.count = collections.Counter()
    self.freqCount = collections.Counter()

  def add(self, number: int) -> None:
    if self.count[number] > 0:
      self.freqCount[self.count[number]] -= 1
    self.count[number] += 1
    self.freqCount[self.count[number]] += 1

  def deleteOne(self, number: int) -> None:
    if self.count[number] == 0:
      return
    self.freqCount[self.count[number]] -= 1
    self.count[number] -= 1
    self.freqCount[self.count[number]] += 1

  def hasFrequency(self, frequency: int) -> bool:
    return self.freqCount[frequency] > 0
