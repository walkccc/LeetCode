class NestedIterator:
  def __init__(self, nestedList: List[NestedInteger]):
    self.stack: List[NestedInteger] = []
    self.addInteger(nestedList)

  def next(self) -> int:
    return self.stack.pop().getInteger()

  def hasNext(self) -> bool:
    while self.stack and not self.stack[-1].isInteger():
      self.addInteger(self.stack.pop().getList())
    return self.stack

  # AddInteger([1, [4, [6]]]) . stack = [[4, [6]], 1]
  # AddInteger([4, [6]]) . stack = [[6], 4]
  # AddInteger([6]) . stack = [6]
  def addInteger(self, nestedList: List[NestedInteger]) -> None:
    for n in reversed(nestedList):
      self.stack.append(n)
