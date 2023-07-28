class Solution:
  def findPrefixScore(self, nums: List[int]) -> List[int]:
    conver = []
    maxi = 0

    for num in nums:
      maxi = max(maxi, num)
      conver.append(num + maxi)

    return itertools.accumulate(conver)
