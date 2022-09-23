# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader:
#   def get(self, index: int) -> int:

class Solution:
  def search(self, reader: 'ArrayReader', target: int) -> int:
    l = 0
    r = 10**4

    while l < r:
      m = (l + r) // 2
      if reader.get(m) < target:
        l = m + 1
      else:
        r = m

    return l if reader.get(l) == target else -1
