class Solution:
  def equalizeWater(self, buckets: list[int], loss: int) -> float:
    ERR = 1e-5
    PERCENTAGE = (100 - loss) / 100
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
      return extra * PERCENTAGE >= need

    while r - l > ERR:
      m = (l + r) / 2
      if canFill(m):
        l = m
      else:
        r = m

    return l
