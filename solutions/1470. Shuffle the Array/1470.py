class Solution:
  def shuffle(self, nums: list[int], n: int) -> list[int]:
    ans = []
    for a, b in zip(nums[:n], nums[n:]):
      ans.append(a)
      ans.append(b)
    return ans
