class T:
  def __init__(self, word: str, freq: int):
    self.word = word
    self.freq = freq

  def __lt__(self, other):
    if self.freq == other.freq:
      # Words with higher frequency and lower alphabetical order are in the
      # bottom of the heap because we'll pop words with lower frequency and
      # higher alphabetical order if the heap's size > k.
      return self.word > other.word
    return self.freq < other.freq


class Solution:
  def topKFrequent(self, words: List[str], k: int) -> List[str]:
    ans = []
    heap = []

    for word, freq in collections.Counter(words).items():
      heapq.heappush(heap, T(word, freq))
      if len(heap) > k:
        heapq.heappop(heap)

    while heap:
      ans.append(heapq.heappop(heap).word)

    return ans[::-1]
