class Solution:
  def duplicateNumbersXOR(self, nums):
    count = collections.Counter(nums)
    return functools.reduce(
        operator.xor, [num for num, freq in count.items() if freq == 2],
        0)
