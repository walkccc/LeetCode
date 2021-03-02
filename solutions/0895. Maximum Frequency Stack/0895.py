class FreqStack:
  def __init__(self):
    self.count = Counter()
    self.countToStack = defaultdict(list)
    self.maxFreq = 0

  def push(self, x: int) -> None:
    self.count[x] += 1
    self.maxFreq = max(self.maxFreq, self.count[x])
    self.countToStack[self.count[x]].append(x)

  def pop(self) -> int:
    value = self.countToStack[self.maxFreq].pop()
    self.count[value] -= 1
    if not self.countToStack[self.maxFreq]:
      self.maxFreq -= 1
    return value
