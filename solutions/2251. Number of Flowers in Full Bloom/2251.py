class Solution:
  def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
    starts = sorted(s for s, _ in flowers)
    ends = sorted(e for _, e in flowers)
    return [bisect_right(starts, p) - bisect_left(ends, p)
            for p in persons]
