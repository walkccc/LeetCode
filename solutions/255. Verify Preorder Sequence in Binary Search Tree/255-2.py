class Solution:
  def verifyPreorder(self, preorder: List[int]) -> List[int]:
    low = -math.inf
    stack = []

    for p in preorder:
      if p < low:
        return False
      while stack and stack[-1] < p:
        low = stack.pop()
      stack.append(p)

    return True
