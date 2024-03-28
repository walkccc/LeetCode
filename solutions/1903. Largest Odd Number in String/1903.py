class Solution:
  def largestOddNumber(self, num: str) -> str:
    for i, n in reversed(list(enumerate(num))):
      if int(n) & 1:
        return num[:i + 1]
    return ''
