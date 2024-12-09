class Solution:
  def minimizeError(self, prices: list[str], target: int) -> str:
    # A[i] := (costCeil - costFloor, costCeil, costFloor)
    # The lower the costCeil - costFloor is, the cheaper to ceil it.
    A = []
    sumFloored = 0
    sumCeiled = 0

    for price in map(float, prices):
      floored = math.floor(price)
      ceiled = math.ceil(price)
      sumFloored += floored
      sumCeiled += ceiled
      costFloor = price - floored
      costCeil = ceiled - price
      A.append((costCeil - costFloor, costCeil, costFloor))

    if not sumFloored <= target <= sumCeiled:
      return '-1'

    A.sort()
    nCeiled = target - sumFloored
    return '{:.3f}'.format(sum(a[1] for a in A[:nCeiled]) +
                           sum(a[2] for a in A[nCeiled:]))
