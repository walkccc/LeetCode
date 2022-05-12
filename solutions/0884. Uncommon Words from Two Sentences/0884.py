class Solution:
  def uncommonFromSentences(self, A: str, B: str) -> List[str]:
    count = Counter((A + ' ' + B).split())
    return [word for word, freq in count.items() if freq == 1]
