class Solution:
  def minCost(self, basket1: List[int], basket2: List[int]) -> int:
    swapped = []
    count = collections.Counter(basket1)
    count.subtract(collections.Counter(basket2))
    
    for num, freq in count.items():
      if freq % 2 != 0:
        return -1
      swapped += [num] * abs(freq // 2)
    
    swapped.sort()
    minNum = min(min(basket1), min(basket2))
    # Other than directly swap basket1[i] and basket2[j], we can swap basket1[i]
    # with `minNum` first then swap `minNum` with basket2[j], and vice versa.
    # That's why we take min(2 * minNum, num) in the below.
    return sum(min(2 * minNum, num) for num in swapped[0:len(swapped) // 2])
  