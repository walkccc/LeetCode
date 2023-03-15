class Solution:
  def minimumRecolors(self, blocks: str, k: int) -> int:
    countB = 0
    maxCountB = 0

    for i, block in enumerate(blocks):
      if block == 'B':
        countB += 1
      if i >= k and blocks[i - k] == 'B':
        countB -= 1
      maxCountB = max(maxCountB, countB)

    return k - maxCountB
