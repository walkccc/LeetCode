class Solution:
  def maximumBeauty(self, flowers: list[int]) -> int:
    ans = -math.inf
    prefix = 0
    flowerToPrefix = collections.defaultdict(int)

    for flower in flowers:
      if flower in flowerToPrefix:
        ans = max(ans, prefix - flowerToPrefix[flower] + flower * 2)
      prefix += max(0, flower)
      flowerToPrefix.setdefault(flower, prefix)

    return ans
