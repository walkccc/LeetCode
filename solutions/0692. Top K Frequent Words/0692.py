class Solution:
  def topKFrequent(self, words: List[str], k: int) -> List[str]:
    ans = []
    bucket = [[] for _ in range(len(words) + 1)]

    for word, freq in Counter(words).items():
      bucket[freq].append(word)

    for b in reversed(bucket):
      for word in sorted(b):
        ans.append(word)
        if len(ans) == k:
          return ans
