class PeekingIterator:
  def __init__(self, iterator: Iterator):
    self.iterator = iterator
    self.buffer = self.iterator.next() if self.iterator.hasNext() else None

  def peek(self) -> int:
    """
    Returns the next element in the iteration without advancing the iterator.
    """
    return self.buffer

  def next(self) -> int:
    next = self.buffer
    self.buffer = self.iterator.next() if self.iterator.hasNext() else None
    return next

  def hasNext(self) -> bool:
    return self.buffer is not None
