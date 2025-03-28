class Solution:
  def findScore(self, nums: list[int]) -> int:
    ans = 0
    seen = set()

    for num, i in sorted([(num, i) for i, num in enumerate(nums)]):
      if i in seen:
        continue
      seen.add(i - 1)
      seen.add(i + 1)
      seen.add(i)
      ans += num

    return ans
