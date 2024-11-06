class Solution:
  def verifyPreorder(self, preorder: list[int]) -> bool:
    low = -math.inf
    i = -1

    for p in preorder:
      if p < low:
        return False
      while i >= 0 and preorder[i] < p:
        low = preorder[i]
        i -= 1
      i += 1
      preorder[i] = p

    return True
