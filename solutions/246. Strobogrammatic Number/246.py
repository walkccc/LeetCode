class Solution:
  def isStrobogrammatic(self, num: str) -> bool:
    rotated = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
    l = 0
    r = len(num) - 1

    while l <= r:
      if num[r] not in rotated:
        return False
      if num[l] != rotated[num[r]]:
        return False
      l += 1
      r -= 1

    return True
