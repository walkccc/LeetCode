class Solution:
  def newInteger(self, n: int) -> int:
    ans = []
    while n:
      ans.append(str(n % 9))
      n //= 9
    return ''.join(ans[::-1])
