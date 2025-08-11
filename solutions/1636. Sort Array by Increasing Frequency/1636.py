from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  num: int
  freq: int

  def __lt__(self, other):
    if self.freq == other.freq:
      return self.num > other.num
    return self.freq < other.freq


class Solution:
  def frequencySort(self, nums: list[int]) -> list[int]:
    ans = []
    heap = []

    for num, freq in collections.Counter(nums).items():
      heapq.heappush(heap, T(num, freq))

    while len(heap) > 0:
      num = heap[0].num
      freq = heapq.heappop(heap).freq
      ans.extend([num] * freq)

    return ans
