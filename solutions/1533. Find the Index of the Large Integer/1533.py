# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader(object):
# # Compares the sum of arr[l..r] with the sum of arr[x..y]
# # return 1 if sum(arr[l..r]) > sum(arr[x..y])
# # return 0 if sum(arr[l..r]) == sum(arr[x..y])
# # return -1 if sum(arr[l..r]) < sum(arr[x..y])
#   def compareSub(self, l: int, r: int, x: int, y: int) -> int:
#
# # Returns the length of the array
#   def length(self) -> int:
#


class Solution:
  def getIndex(self, reader: 'ArrayReader') -> int:
    l = 0
    r = reader.length() - 1

    while l < r:
      m = (l + r) // 2
      if (r - l) % 2 == 0:
        res = reader.compareSub(l, m - 1, m + 1, r)
        if res == 0:
          return m
        if res == 1:
          r = m - 1
        else:  # res == -1
          l = m + 1
      else:
        res = reader.compareSub(l, m, m + 1, r)
        # res is either 1 or -1.
        if res == 1:
          r = m
        else:  # res == -1
          l = m + 1

    return l
