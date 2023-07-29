class MyCalendar:
  def __init__(self):
    self.timeline = []

  def book(self, start: int, end: int) -> bool:
    for s, e in self.timeline:
      if max(start, s) < min(end, e):
        return False
    self.timeline.append((start, end))
    return True
