class Solution:
  def addNegabinary(self, arr1: list[int], arr2: list[int]) -> list[int]:
    ans = []
    carry = 0

    while carry != 0 or arr1 or arr2:
      if arr1:
        carry += arr1.pop()
      if arr2:
        carry += arr2.pop()
      ans.append(carry & 1)
      carry = -(carry >> 1)

    while len(ans) > 1 and ans[-1] == 0:
      ans.pop()

    return ans[::-1]
