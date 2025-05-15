class Solution:
  def uncommonFromSentences(self, A: str, B: str) -> list[str]:
    count = collections.Counter((A + ' ' + B).split())
    return [word for word, freq in count.items() if freq == 1]
