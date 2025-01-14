class Solution:
  def sumOfPower(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    ans = 0
    summ = 0

    for num in sorted(nums):
      ans += (num + summ) * num**2
      ans %= kMod
      summ = (summ * 2 + num) % kMod

    return ans
