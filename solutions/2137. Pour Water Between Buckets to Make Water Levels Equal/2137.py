class Solution:
  def equalizeWater(self, buckets: list[int], loss: int) -> float:
    kErr = 1e-5
    kPercentage = (100 - loss) / 100
    l = 0.0
    r = max(buckets)

    def canFill(target: float) -> bool:
      extra = 0
      need = 0
      for bucket in buckets:
        if bucket > target:
          extra += bucket - target
        else:
          need += target - bucket
      return extra * kPercentage >= need

    while r - l > kErr:
      m = (l + r) / 2
      if canFill(m):
        l = m
      else:
        r = m

    return l
