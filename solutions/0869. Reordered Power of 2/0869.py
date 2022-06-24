class Solution:
  def reorderedPowerOf2(self, N: int) -> bool:
    count = Counter(str(N))
    return any(Counter(str(1 << i)) == count for i in range(30))
