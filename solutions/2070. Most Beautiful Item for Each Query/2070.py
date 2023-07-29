class Solution:
  def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
    prices, beauties = zip(*sorted(items))
    maxBeautySoFar = [0] * (len(beauties) + 1)

    for i, beauty in enumerate(beauties):
      maxBeautySoFar[i + 1] = max(maxBeautySoFar[i], beauty)

    return [maxBeautySoFar[bisect_right(prices, query)] for query in queries]
