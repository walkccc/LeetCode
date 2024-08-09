class Solution:
  def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
    ans = []
    wordsFreq = sorted([word.count(min(word)) for word in words])

    for q in queries:
      count = q.count(min(q))
      index = bisect.bisect(wordsFreq, count)
      ans.append(len(words) - index)

    return ans
