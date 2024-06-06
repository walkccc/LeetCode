class Solution:
  def addStrings(self, num1: str, num2: str) -> str:
    ans = []
    carry = 0
    i = len(num1) - 1
    j = len(num2) - 1

    while i >= 0 or j >= 0 or carry:
      if i >= 0:
        carry += int(num1[i])
      if j >= 0:
        carry += int(num2[j])
      ans.append(str(carry % 10))
      carry //= 10
      i -= 1
      j -= 1

    return ''.join(reversed(ans))
