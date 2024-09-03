class Solution:
  def secondHighest(self, s: str) -> int:
    maxDigit = -1
    secondMaxDigit = -1

    for c in s:
      if c.isdigit():
        d = int(c)
        if d > maxDigit:
          secondMaxDigit = maxDigit
          maxDigit = d
        elif maxDigit > d > secondMaxDigit:
          secondMaxDigit = d

    return secondMaxDigit
