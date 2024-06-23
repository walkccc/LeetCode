class Solution:
  def shortestToChar(self, s: str, c: str) -> List[int]:
    n = len(s)
    ans = [0] * n
    prev = -n

    for i in range(n):
      if s[i] == c:
        prev = i
      ans[i] = i - prev

    for i in range(prev - 1, -1, -1):
      if s[i] == c:
        prev = i
      ans[i] = min(ans[i], prev - i)

    return ans
