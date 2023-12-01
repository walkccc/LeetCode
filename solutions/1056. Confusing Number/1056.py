class Solution:
  def confusingNumber(self, n: int) -> bool:
    s = str(n)
    rotated = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
    rotatedNum = []

    for c in s[::-1]:
      if c not in rotated:
        return False
      rotatedNum.append(rotated[c])

    return ''.join(rotatedNum) != s
