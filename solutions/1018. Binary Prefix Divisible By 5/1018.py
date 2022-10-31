class Solution:
  def prefixesDivBy5(self, A: List[int]) -> List[bool]:
    ans = []
    num = 0

    for a in A:
      num = (num * 2 + a) % 5
      ans.append(num % 5 == 0)

    return ans
