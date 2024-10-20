class Solution:
  def toHex(self, num: int) -> str:
    if num == 0:
      return '0'

    hex = '0123456789abcdef'
    ans = []

    # Handling negative numbers by using 32-bit unsigned representation Python's
    # bitwise operation works on signed numbers, so we convert to 32-bit
    # unsigned for negative numbers.
    if num < 0:
      num += 2**32

    while num > 0:
      ans.append(hex[num & 0xF])
      num >>= 4

    return ''.join(reversed(ans))
