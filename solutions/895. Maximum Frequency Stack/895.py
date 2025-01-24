class FreqStack:
  def __init__(self):
    self.maxFreq = 0
    self.count = collections.Counter()
    self.countToStack = collections.defaultdict(list)

  def push(self, val: int) -> None:
    self.count[val] += 1
    self.countToStack[self.count[val]].append(val)
    self.maxFreq = max(self.maxFreq, self.count[val])

  def pop(self) -> int:
    val = self.countToStack[self.maxFreq].pop()
    self.count[val] -= 1
    if not self.countToStack[self.maxFreq]:
      self.maxFreq -= 1
    return val
