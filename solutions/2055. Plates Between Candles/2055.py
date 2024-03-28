class Solution:
  def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
    ans = []
    indices = [i for i, c in enumerate(s) if c == '|']  # indices of '|'

    for left, right in queries:
      l = bisect.bisect_left(indices, left)
      r = bisect.bisect_right(indices, right) - 1
      if l < r:
        lengthBetweenCandles = indices[r] - indices[l] + 1
        numCandles = r - l + 1
        ans.append(lengthBetweenCandles - numCandles)
      else:
        ans.append(0)

    return ans
