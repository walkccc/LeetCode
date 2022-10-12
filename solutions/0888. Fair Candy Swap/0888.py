class Solution:
  def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
    diff = (sum(A) - sum(B)) // 2
    B = set(B)

    for a in A:
      if a - diff in B:
        return [a, a - diff]
