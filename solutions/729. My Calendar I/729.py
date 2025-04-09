class MyCalendar:
  def __init__(self):
    self.line = []

  def book(self, startTime: int, endTime: int) -> bool:
    for s, e in self.line:
      if max(startTime, s) < min(endTime, e):
        return False
    self.line.append((startTime, endTime))
    return True
