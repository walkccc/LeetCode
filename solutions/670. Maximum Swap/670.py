class Solution:
  def maximumSwap(self, num: int) -> int:
    s = list(str(num))
    dict = {c: i for i, c in enumerate(s)}

    for i, c in enumerate(s):
      for digit in reversed(string.digits):
        if digit <= c:
          break
        if digit in dict and dict[digit] > i:
          s[i], s[dict[digit]] = digit, s[i]
          return int(''.join(s))

    return num
