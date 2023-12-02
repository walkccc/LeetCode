class Solution:
  def findMaxAverage(self, nums: List[int], k: int) -> float:
    kErr = 1e-5
    l = min(nums)
    r = max(nums)

    def check(m: float) -> bool:
      """
      Returns True if there's a subarray, where its length >= k and its average
      sum >= m.
      """
      summ = 0
      prevSum = 0
      minPrevSum = 0

      for i, num in enumerate(nums):
        # Need to substract m for each `num` so that we can check if the sum of
        # the subarray >= 0.
        summ += num - m
        if i >= k:
          prevSum += nums[i - k] - m
          minPrevSum = min(minPrevSum, prevSum)
        if i + 1 >= k and summ >= minPrevSum:
          return True

      return False

    while r - l > kErr:
      m = (l + r) / 2
      if check(m):
        l = m
      else:
        r = m

    return l
