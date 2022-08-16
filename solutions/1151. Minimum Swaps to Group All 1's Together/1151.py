class Solution:
  def minSwaps(self, data: List[int]) -> int:
    k = data.count(1)
    ones = 0  # ones in window
    maxOnes = 0  # max ones in window

    for i, num in enumerate(data):
      if i >= k and data[i - k]:
        ones -= 1
      if num:
        ones += 1
      maxOnes = max(maxOnes, ones)

    return k - maxOnes
