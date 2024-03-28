class Fancy:
  def __init__(self):
    self.kMod = 1_000_000_007
    # For each `val` in `vals`, it actually represents a * val + b.
    self.vals = []
    self.a = 1
    self.b = 0

  # To undo a * val + b and get the original value, we append (val - b) // a.
  # By Fermat's little theorem:
  #   a^(p - 1) ≡ 1 (mod p)
  #   a^(p - 2) ≡ a^(-1) (mod p)
  # So, (val - b) / a ≡ (val - b) * a^(p - 2) (mod p)
  def append(self, val: int) -> None:
    x = (val - self.b + self.kMod) % self.kMod
    self.vals.append(x * pow(self.a, self.kMod - 2, self.kMod))

  # If the value is a * val + b, then the value after adding by `inc` will be
  # a * val + b + inc. So, we adjust b to b + inc.
  def addAll(self, inc: int) -> None:
    self.b = (self.b + inc) % self.kMod

  # If the value is a * val + b, then the value after multiplying by `m` will
  # be a * m * val + b * m. So, we adjust a to a * m and b to b * m.
  def multAll(self, m: int) -> None:
    self.a = (self.a * m) % self.kMod
    self.b = (self.b * m) % self.kMod

  def getIndex(self, idx: int) -> int:
    return -1 if idx >= len(self.vals) \
        else (self.a * self.vals[idx] + self.b) % self.kMod
