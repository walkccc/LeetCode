class FrontMiddleBackQueue:
  def __init__(self):
    self.frontQueue = collections.deque()
    self.backQueue = collections.deque()

  def pushFront(self, val: int) -> None:
    self.frontQueue.appendleft(val)
    self._moveFrontToBackIfNeeded()

  def pushMiddle(self, val: int) -> None:
    if len(self.frontQueue) == len(self.backQueue):
      self.backQueue.appendleft(val)
    else:
      self.frontQueue.append(val)

  def pushBack(self, val: int) -> None:
    self.backQueue.append(val)
    self._moveBackToFrontIfNeeded()

  def popFront(self) -> int:
    if self.frontQueue:
      x = self.frontQueue.popleft()
      self._moveBackToFrontIfNeeded()
      return x
    if self.backQueue:
      return self.backQueue.popleft()
    return -1

  def popMiddle(self) -> int:
    if not self.frontQueue and not self.backQueue:
      return -1
    if len(self.frontQueue) + 1 == len(self.backQueue):
      return self.backQueue.popleft()
    return self.frontQueue.pop()

  def popBack(self) -> int:
    if self.backQueue:
      x = self.backQueue.pop()
      self._moveFrontToBackIfNeeded()
      return x
    return -1

  def _moveFrontToBackIfNeeded(self) -> None:
    if len(self.frontQueue) - 1 == len(self.backQueue):
      self.backQueue.appendleft(self.frontQueue.pop())

  def _moveBackToFrontIfNeeded(self) -> None:
    if len(self.frontQueue) + 2 == len(self.backQueue):
      self.frontQueue.append(self.backQueue.popleft())
