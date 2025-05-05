class Bucket:
  def __init__(self, mn: int, mx: int):
    self.mn = mn
    self.mx = mx


class Solution:
  def maximumGap(self, nums: list[int]) -> int:
    if len(nums) < 2:
      return 0

    mn = min(nums)
    mx = max(nums)
    if mn == mx:
      return 0

    gap = math.ceil((mx - mn) / (len(nums) - 1))
    bucketSize = (mx - mn) // gap + 1
    buckets = [Bucket(math.inf, -math.inf) for _ in range(bucketSize)]

    for num in nums:
      i = (num - mn) // gap
      buckets[i].mn = min(buckets[i].mn, num)
      buckets[i].mx = max(buckets[i].mx, num)

    ans = 0
    prevMax = mn

    for bucket in buckets:
      if bucket.mn == math.inf:
        continue  # empty bucket
      ans = max(ans, bucket.mn - prevMax)
      prevMax = bucket.mx

    return ans
