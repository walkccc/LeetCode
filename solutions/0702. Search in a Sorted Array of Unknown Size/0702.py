# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# Class ArrayReader:
#   def get(self, index: int) -> int:

class Solution:
  def search(self, reader: 'ArrayReader', target: int) -> int:
    l = bisect.bisect_left(range(10**4), target,
                           key=lambda m: reader.get(m))
    return l if reader.get(l) == target else -1
