from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  word: str
  freq: int

  def __lt__(self, other):
    if self.freq == other.freq:
      return self.word > other.word
    return self.freq < other.freq


class Solution:
  def topKFrequent(self, words: list[str], k: int) -> list[str]:
    ans = []
    heap = []

    for word, freq in collections.Counter(words).items():
      heapq.heappush(heap, T(word, freq))
      if len(heap) > k:
        heapq.heappop(heap)

    while heap:
      ans.append(heapq.heappop(heap).word)

    return ans[::-1]
