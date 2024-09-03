class Solution:
  # Similar to 1995. Count Special Quadruplets
  def divisibleTripletCount(self, nums: list[int], d: int) -> int:
    ans = 0
    count = collections.Counter()

    for j in range(len(nums) - 1, 0, -1):  # `j` also represents k.
      for i in range(j - 1, -1, -1):
        ans += count[-(nums[i] + nums[j]) % d]
      count[nums[j] % d] += 1  # j := k

    return ans
