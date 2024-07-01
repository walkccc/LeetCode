class Solution:
  def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
    ans = []
    carry = 0

    while carry or arr1 or arr2:
      if arr1:
        carry += arr1.pop()
      if arr2:
        carry += arr2.pop()
      ans.append(carry & 1)
      carry = -(carry >> 1)

    while len(ans) > 1 and ans[-1] == 0:
      ans.pop()

    return ans[::-1]
