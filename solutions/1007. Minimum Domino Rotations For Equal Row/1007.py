class Solution:
  def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
    for num in range(1, 7):
      if all(num in pair for pair in zip(tops, bottoms)):
        return len(tops) - max(tops.count(num), bottoms.count(num))
    return -1
