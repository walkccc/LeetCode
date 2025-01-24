class Solution:
  def findInteger(self, k: int, digit1: int, digit2: int) -> int:
    minDigit = min(digit1, digit2)
    maxDigit = max(digit1, digit2)
    digits = [minDigit] if minDigit == maxDigit else [minDigit, maxDigit]
    q = collections.deque()

    for digit in digits:
      q.append(digit)

    while q:
      u = q.popleft()
      if u > k and u % k == 0:
        return u
      if u == 0:
        continue
      for digit in digits:
        nextNum = u * 10 + digit
        if nextNum > 2**31 - 1:
          continue
        q.append(nextNum)

    return -1
