class Solution:
  def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
    ans = []
    A = [i for i, c in enumerate(s) if c == '|']  # indices of '|'

    for left, right in queries:
      l = bisect_left(A, left)
      r = bisect_right(A, right) - 1
      if l < r:
        lengthBetweenCandles = A[r] - A[l] + 1
        numCandles = r - l + 1
        ans.append(lengthBetweenCandles - numCandles)
      else:
        ans.append(0)

    return ans
