# """
# This is the ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader(object):
#   # Compares 4 different elements in the array
#   # Returns 4 if the values of the 4 elements are the same (0 or 1).
#   # Returns 2 if three elements have a value equal to 0 and one element has
#   #           value equal to 1 or vice versa.
#   # Returns 0 if two element have a value equal to 0 and two elements have a
#   #           value equal to 1.
#   def query(self, a: int, b: int, c: int, d: int) -> int:
#
#   # Returns the length of the array
#   def length(self) -> int:
#

class Solution:
  def guessMajority(self, reader: 'ArrayReader') -> int:
    n = reader.length()
    query0123 = reader.query(0, 1, 2, 3)
    query1234 = reader.query(1, 2, 3, 4)
    zeros = 1  # the number of numbers that are same as `nums[0]`
    nonZeros = 0  # the number of numbers that are different from `nums[0]`
    indexNot0 = -1  # any index i s.t. nums[i] != nums[0]

    # Find which group nums[1..3] belong to.
    for i in range(1, 4):
      abcd = [0] + [num for num in [1, 2, 3] if num != i] + [4]
      if reader.query(*abcd) == query1234:  # nums[i] == nums[0]
        zeros += 1
      else:
        nonZeros += 1
        indexNot0 = i

    # Find which group nums[4..n) belong to.
    for i in range(4, n):
      if reader.query(1, 2, 3, i) == query0123:  # nums[i] == nums[0]
        zeros += 1
      else:
        nonZeros += 1
        indexNot0 = i

    if zeros == nonZeros:
      return -1
    if zeros > nonZeros:
      return 0
    return indexNot0
