class Solution:
  def numberOfSubsequences(self, nums: list[int]) -> int:
    n = len(nums)
    mx = max(nums)
    ans = 0
    count = [[0] * (mx + 1) for _ in range(mx + 1)]

    # nums[p] * nums[r] == nums[q] * nums[s]
    # nums[p] / nums[q] == nums[s] / nums[r]
    for r in range(4, n - 1 - 2 + 1):
      q = r - 2
      for p in range(0, q - 2 + 1):
        g = math.gcd(nums[p], nums[q])
        count[nums[p] // g][nums[q] // g] += 1
      for s in range(r + 2, n):
        g = math.gcd(nums[s], nums[r])
        ans += count[nums[s] // g][nums[r] // g]

    return ans
