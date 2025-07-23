class Solution:
  def numSmallerByFrequency(
      self,
      queries: list[str],
      words: list[str],
  ) -> list[int]:
    ans = []
    wordsFreq = sorted([word.count(min(word)) for word in words])

    for q in queries:
      count = q.count(min(q))
      index = bisect.bisect(wordsFreq, count)
      ans.append(len(words) - index)

    return ans
