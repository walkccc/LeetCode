class Solution:
  def validUtf8(self, data: list[int]) -> bool:
    followedBytes = 0

    for d in data:
      if followedBytes == 0:
        if (d >> 3) == 0b11110:
          followedBytes = 3
        elif (d >> 4) == 0b1110:
          followedBytes = 2
        elif (d >> 5) == 0b110:
          followedBytes = 1
        elif (d >> 7) == 0b0:
          followedBytes = 0
        else:
          return False
      else:
        if (d >> 6) != 0b10:
          return False
        followedBytes -= 1

    return followedBytes == 0
