class Solution:
  def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
    n = len(flowers)

    # if a garden is already complete, clamp it to target
    flowers = [min(flower, target) for flower in flowers]
    flowers.sort()

    # all gardens are complete, nothing we can do
    if flowers[0] == target:
      return n * full

    # have many new flowers, can maximize beauty value
    if newFlowers >= n * target - sum(flowers):
      return max(n * full, (n - 1) * full + (target - 1) * partial)

    ans = 0
    leftFlowers = newFlowers
    # cost[i] := cost to make flowers[0..i] the same
    cost = [0] * n

    for i in range(1, n):
      # plant (flowers[i] - flowers[i - 1]) flowers for flowers[0..i - 1]
      cost[i] = cost[i - 1] + i * (flowers[i] - flowers[i - 1])

    i = n - 1  # flowers' index (flowers[i + 1:] are complete)
    while flowers[i] == target:
      i -= 1

    while leftFlowers >= 0:
      # to maximize the min # of incomplete flowers, we find the first index j
      # that we can't make flowers[0..j] equal to flowers[j], then we know we
      # can make flowers[0..j - 1] equal to flowers[j - 1], in the meantime,
      # evenly increase each of them to seek a bigger min value
      j = min(i + 1, bisect_right(cost, leftFlowers))
      minIncomplete = flowers[j - 1] + (leftFlowers - cost[j - 1]) // j
      ans = max(ans, (n - 1 - i) * full + minIncomplete * partial)
      leftFlowers -= max(0, target - flowers[i])
      i -= 1

    return ans
