class MyCalendar:
  def __init__(self):
    self.ranges = []

  def book(self, start: int, end: int) -> bool:
    for s, e in self.ranges:
      if max(start, s) < min(end, e):
        return False
    self.ranges.append((start, end))
    return True
