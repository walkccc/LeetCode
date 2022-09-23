class Bitset:
  def __init__(self, size: int):
    self.s = ['0'] * size
    self.r = ['1'] * size
    self.cnt = 0

  def fix(self, idx: int) -> None:
    if self.s[idx] == '0':
      self.cnt += 1
    self.s[idx] = '1'
    self.r[idx] = '0'

  def unfix(self, idx: int) -> None:
    if self.s[idx] == '1':
      self.cnt -= 1
    self.s[idx] = '0'
    self.r[idx] = '1'

  def flip(self) -> None:
    self.s, self.r = self.r, self.s
    self.cnt = len(self.s) - self.cnt

  def all(self) -> bool:
    return self.cnt == len(self.s)

  def one(self) -> bool:
    return self.cnt

  def count(self) -> int:
    return self.cnt

  def toString(self) -> str:
    return ''.join(self.s)
