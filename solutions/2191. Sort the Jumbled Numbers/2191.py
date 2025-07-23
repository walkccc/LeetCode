class Solution:
  def sortJumbled(self, mapping: list[int], nums: list[int]) -> list[int]:
    def getMapped(num: int) -> int:
      mapped = []
      for c in str(num):
        mapped.append(str(mapping[int(c)]))
      return int(''.join(mapped))
    A = [(getMapped(num), i, num) for i, num in enumerate(nums)]
    return [num for _, i, num in sorted(A)]
