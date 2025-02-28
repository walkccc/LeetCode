class Solution:
  def numberOfPairs(self, nums: list[int]) -> list[int]:
    ans = [0] * 2
    count = collections.Counter(nums)

    for i in range(101):
      ans[0] += count[i] // 2
      ans[1] += count[i] & 1

    return ans
