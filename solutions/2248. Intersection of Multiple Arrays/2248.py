class Solution:
  def intersection(self, nums: list[list[int]]) -> list[int]:
    count = [0] * 1001

    for A in nums:
      for a in A:
        count[a] += 1

    return [i for i, c in enumerate(count)
            if c == len(nums)]
