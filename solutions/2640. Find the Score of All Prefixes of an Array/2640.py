class Solution:
  def findPrefixScore(self, nums: list[int]) -> list[int]:
    conver = []
    mx = 0

    for num in nums:
      mx = max(mx, num)
      conver.append(num + mx)

    return itertools.accumulate(conver)
