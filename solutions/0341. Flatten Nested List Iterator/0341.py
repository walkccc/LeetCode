class NestedIterator:
  def __init__(self, nestedList: List[NestedInteger]):
    self.q = deque()
    self.addInteger(nestedList)

  def next(self) -> int:
    return self.q.popleft()

  def hasNext(self) -> bool:
    return self.q

  def addInteger(self, nestedList: List[NestedInteger]) -> None:
    for ni in nestedList:
      if ni.isInteger():
        self.q.append(ni.getInteger())
      else:
        self.addInteger(ni.getList())
