class Solution:
  def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
    for i, flower in enumerate(flowerbed):
      if flower == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0):
        flowerbed[i] = 1
        n -= 1
      if n <= 0:
        return True

    return False
