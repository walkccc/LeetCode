"""
The read4 API is already defined for you.
    def read4(buf4: List[chr]) -> int:

# Below is an example of how the read4 API can be called.
file = File("abcdefghijk") # File is "abcdefghijk", initially file pointer (fp) points to 'a'
buf4 = [' '] * 4 # Create buffer with enough space to store characters
read4(buf4) # read4 returns 4. Now buf = ['a','b','c','d'], fp points to 'e'
read4(buf4) # read4 returns 4. Now buf = ['e','f','g','h'], fp points to 'i'
read4(buf4) # read4 returns 3. Now buf = ['i','j','k',...], fp points to end of file
"""


class Solution:
  def read(self, buf: List[str], n: int) -> int:
    buf4 = [' '] * 4
    i4 = 0  # buf4's index
    n4 = 0  # buf4's size
    i = 0  # buf's index

    while i < n:
      if i4 == n4:  # all characters in buf4 are consumed
        i4 = 0  # reset buf4's index
        n4 = read4(buf4)  # read 4 (or less) chars from file to buf4
        if n4 == 0:  # reach the EOF
          return i
      buf[i] = buf4[i4]
      i += 1
      i4 += 1

    return i
