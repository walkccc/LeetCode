class Solution:
  def findLHS(self, nums: List[int]) -> int:
    ans = 0
    count = Counter(nums)

    for num, freq in count.items():
      if num + 1 in count:
        ans = max(ans, freq + count[num + 1])

    return ans
