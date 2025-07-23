class Solution:
  def areNumbersAscending(self, s: str) -> bool:
    prev = 0

    for token in s.split():
      if token.isdigit():
        num = int(token)
        if num <= prev:
          return False
        prev = num

    return True
