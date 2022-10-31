class Solution:
  def numberOfPairs(self, nums: List[int]) -> List[int]:
    ans = [0] * 2
    count = Counter(nums)

    for i in range(101):
      ans[0] += count[i] // 2
      ans[1] += count[i] & 1

    return ans
