class Solution:
  def minimizeXor(self, num1: int, num2: int) -> int:
    kMaxBit = 30
    bits = num2.bit_count()
    # can turn off all bits in num1
    if num1.bit_count() == bits:
      return num1

    ans = 0

    # turn off MSB if we have bits quota
    for i in reversed(range(kMaxBit)):
      if num1 >> i & 1:
        ans |= 1 << i
        bits -= 1
        if bits == 0:
          return ans

    # turn on LSB if we still have bits
    for i in range(kMaxBit):
      if (num1 >> i & 1) == 0:
        ans |= 1 << i
        bits -= 1
        if bits == 0:
          return ans

    return ans
