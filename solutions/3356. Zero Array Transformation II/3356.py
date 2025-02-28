class Solution:
  def minZeroArray(self, nums: list[int], queries: list[list[int]]) -> int:
    line = [0] * (len(nums) + 1)
    decrement = 0
    k = 0

    for i, num in enumerate(nums):
      while decrement + line[i] < num:
        if k == len(queries):
          return -1
        l, r, val = queries[k]
        k += 1
        if r < i:
          continue
        line[max(l, i)] += val
        line[r + 1] -= val
      decrement += line[i]

    return k
