class Solution:
  def rearrangeArray(self, nums: list[int]) -> list[int]:
    ans = []
    pos = []
    neg = []

    for num in nums:
      (pos if num > 0 else neg).append(num)

    for p, n in zip(pos, neg):
      ans += [p, n]

    return ans
