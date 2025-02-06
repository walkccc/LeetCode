class PhoneDirectory:
  def __init__(self, maxNumbers: int):
    # the next available numbers
    self.next = [i + 1 for i in range(maxNumbers - 1)] + [0]
    # the current possible available number
    self.number = 0

  def get(self) -> int:
    if self.next[self.number] == -1:
      return -1
    ans = self.number
    self.number = self.next[self.number]
    self.next[ans] = -1  # Mark as used.
    return ans

  def check(self, number: int) -> bool:
    return self.next[number] != -1

  def release(self, number: int) -> None:
    if self.next[number] != -1:
      return
    self.next[number] = self.number
    self.number = number
