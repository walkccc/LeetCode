class Solution:
  def nthSuperUglyNumber(self, n: int, primes: list[int]) -> int:
    k = len(primes)
    nums = [1]
    indices = [0] * k

    while len(nums) < n:
      nexts = [0] * k
      for i in range(k):
        nexts[i] = nums[indices[i]] * primes[i]
      next = min(nexts)
      for i in range(k):
        if next == nexts[i]:
          indices[i] += 1
      nums.append(next)

    return nums[-1]
