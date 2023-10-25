class T:
  def __init__(self, word: str, freq: int):
    self.word = word
    self.freq = freq

  def __lt__(self, other):
    if self.freq == other.freq:
      # Words w/ higher frequency and lower alphabetical order are in the bottom
      # Of the heap, because we'll pop words w/ lower frequency and higher
      # Alphabetical order if the heap's size > k
      return self.word > other.word
    return self.freq < other.freq


class Solution:
  def topKFrequent(self, words: List[str], k: int) -> List[str]:
    ans = []
    heap = []  # Sorted by freq then alphabet

    for word, freq in collections.Counter(words).items():
      heapq.heappush(heap, T(word, freq))
      if len(heap) > k:
        heapq.heappop(heap)

    while heap:
      ans.append(heapq.heappop(heap).word)

    return ans[::-1]
