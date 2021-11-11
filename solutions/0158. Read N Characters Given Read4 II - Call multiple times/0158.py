# The read4 API is already defined for you.
# def read4(buf4: List[str]) -> int:

class Solution:
  def read(self, buf: List[str], n: int) -> int:
    i = 0  # buf's index

    while i < n:
      if self.i4 == self.n4:  # all characters in buf4 are consumed
        self.i4 = 0  # reset buf4's index
        self.n4 = read4(self.buf4)  # read 4 (or less) chars from file to buf4
        if self.n4 == 0:  # reach the EOF
          return i
      buf[i] = self.buf4[self.i4]
      i += 1
      self.i4 += 1

    return i

  buf4 = [' '] * 4
  i4 = 0  # buf4's index
  n4 = 0  # buf4's size
