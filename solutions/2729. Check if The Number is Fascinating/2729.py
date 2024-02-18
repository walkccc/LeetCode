class Solution:
  def isFascinating(self, n):
    s = str(n) + str(2 * n) + str(3 * n)
    return ''.join(sorted(s)) == '123456789'
