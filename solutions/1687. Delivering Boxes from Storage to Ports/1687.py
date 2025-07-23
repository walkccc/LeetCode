class Solution:
  def boxDelivering(
      self,
      boxes: list[list[int]],
      portsCount: int,
      maxBoxes: int,
      maxWeight: int,
  ) -> int:
    n = len(boxes)
    # dp[i] := the minimum trips to deliver boxes[0..i) and return to the
    # storage
    dp = [0] * (n + 1)
    trips = 2
    weight = 0

    l = 0
    for r in range(n):
      weight += boxes[r][1]

      # The current box is different from the previous one, need to make one
      # more trip.
      if r > 0 and boxes[r][0] != boxes[r - 1][0]:
        trips += 1

      # Loading boxes[l] in the previous turn is always no bad than loading it
      # in this turn
      while r - l + 1 > maxBoxes or weight > maxWeight or (
              l < r and dp[l + 1] == dp[l]):
        weight -= boxes[l][1]
        if boxes[l][0] != boxes[l + 1][0]:
          trips -= 1
        l += 1

      #   min trips to deliver boxes[0..r]
      # = min trips to deliver boxes[0..l) + trips to deliver boxes[l..r]
      dp[r + 1] = dp[l] + trips

    return dp[n]
