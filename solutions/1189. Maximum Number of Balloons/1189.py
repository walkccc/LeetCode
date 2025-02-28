class Solution:
  def maxNumberOfBalloons(self, text: str) -> int:
    count = collections.Counter(text)
    return min(
        count['b'],
        count['a'],
        count['l'] // 2, count['o'] // 2, count['n'])
