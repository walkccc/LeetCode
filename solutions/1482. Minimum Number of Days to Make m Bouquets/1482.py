class Solution:
  def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
    if len(bloomDay) < m * k:
      return -1

    def getBouquetCount(waitingDays: int) -> int:
      """
      Returns the number of bouquets (k flowers needed) can be made after the
      `waitingDays`.
      """
      bouquetCount = 0
      requiredFlowers = k
      for day in bloomDay:
        if day > waitingDays:
          # Reset `requiredFlowers` since there was not enough adjacent flowers.
          requiredFlowers = k
        else:
          requiredFlowers -= 1
          if requiredFlowers == 0:
            # Use k adjacent flowers to make a bouquet.
            bouquetCount += 1
            requiredFlowers = k
      return bouquetCount

    l = min(bloomDay)
    r = max(bloomDay)

    while l < r:
      mid = (l + r) // 2
      if getBouquetCount(mid) >= m:
        r = mid
      else:
        l = mid + 1

    return l
