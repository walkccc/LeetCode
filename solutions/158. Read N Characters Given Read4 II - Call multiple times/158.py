# The read4 API is already defined for you.
# Def read4(buf4: list[str]) -> int:

class Solution:
  def read(self, buf: list[str], n: int) -> int:
    i = 0  # buf's index

    while i < n:
      if self.i4 == self.n4:  # All the characters in the buf4 are consumed.
        self.i4 = 0  # Reset the buf4's index.
        # Read <= 4 characters from the file to the buf4.
        self.n4 = read4(self.buf4)
        if self.n4 == 0:  # Reach the EOF.
          return i
      buf[i] = self.buf4[self.i4]
      i += 1
      self.i4 += 1

    return i

  buf4 = [' '] * 4
  i4 = 0  # buf4's index
  n4 = 0  # buf4's size
