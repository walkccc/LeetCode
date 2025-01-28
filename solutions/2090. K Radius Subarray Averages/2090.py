class Solution:
  def getAverages(self, nums: list[int], k: int) -> list[int]:
    n = len(nums)
    size = 2 * k + 1
    ans = [-1] * n
    if size > n:
      return ans

    summ = sum(nums[:size])

    for i in range(k, n - k):
      ans[i] = summ // size
      if i + k + 1 < n:
        summ += nums[i + k + 1] - nums[i - k]

    return ans
