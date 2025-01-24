class Solution:
  # Same as 2100. Find Good Days to Rob the Bank
  def goodIndices(self, nums: list[int], k: int) -> list[int]:
    n = len(nums)
    dec = [1] * n  # 1 + the number of continuous decreasing numbers before i
    inc = [1] * n  # 1 + the number of continuous increasing numbers after i

    for i in range(1, n):
      if nums[i - 1] >= nums[i]:
        dec[i] = dec[i - 1] + 1

    for i in range(n - 2, -1, -1):
      if nums[i] <= nums[i + 1]:
        inc[i] = inc[i + 1] + 1

    return [i for i in range(k, n - k)
            if dec[i - 1] >= k and inc[i + 1] >= k]
