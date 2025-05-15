from sortedcontainers import SortedDict


class MyCalendarThree:
  def __init__(self):
    self.line = SortedDict()

  def book(self, start: int, end: int) -> int:
    self.line[start] = self.line.get(start, 0) + 1
    self.line[end] = self.line.get(end, 0) - 1

    ans = 0
    activeEvents = 0

    for count in self.line.values():
      activeEvents += count
      ans = max(ans, activeEvents)

    return ans
