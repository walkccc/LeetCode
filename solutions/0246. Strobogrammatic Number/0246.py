class Solution:
  def isStrobogrammatic(self, num: str) -> bool:
    rotated = ['0', '1', 'x', 'x', 'x',
               'x', '9', 'x', '8', '6']
    l = 0
    r = len(num) - 1

    while l <= r:
      if num[l] != rotated[ord(num[r]) - ord('0')]:
        return False
      l += 1
      r -= 1

    return True
