class Solution:
  def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
    starts = sorted(s for s, _ in flowers)
    ends = sorted(e for _, e in flowers)
    return [bisect.bisect_right(starts, person) -
            bisect.bisect_left(ends, person)
            for person in persons]
