class NestedIterator:
  def __init__(self, nestedList: list[NestedInteger]):
    self.stack: list[NestedInteger] = []
    self.addInteger(nestedList)

  def next(self) -> int:
    return self.stack.pop().getInteger()

  def hasNext(self) -> bool:
    while self.stack and not self.stack[-1].isInteger():
      self.addInteger(self.stack.pop().getList())
    return self.stack

  # addInteger([1, [4, [6]]]) . stack = [[4, [6]], 1]
  # addInteger([4, [6]]) . stack = [[6], 4]
  # addInteger([6]) . stack = [6]
  def addInteger(self, nestedList: list[NestedInteger]) -> None:
    for n in reversed(nestedList):
      self.stack.append(n)
