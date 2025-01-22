from sortedcontainers import SortedDict


class CountIntervals:
  def __init__(self):
    self.intervals = SortedDict()
    self.cnt = 0

  def add(self, left: int, right: int) -> None:
    while self._isOverlapped(left, right):
      i = self.intervals.bisect_right(right) - 1
      l, r = self.intervals.popitem(i)
      left = min(left, l)
      right = max(right, r)
      self.cnt -= r - l + 1

    self.intervals[left] = right
    self.cnt += right - left + 1

  def count(self) -> int:
    return self.cnt

  def _isOverlapped(self, left: int, right: int) -> bool:
    i = self.intervals.bisect_right(right)
    return i > 0 and self.intervals.peekitem(i - 1)[1] >= left
