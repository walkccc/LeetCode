class Solution:
  def isValidSerialization(self, preorder: str) -> bool:
    degree = 1  # out-degree (children) - in-degree (parent)

    for node in preorder.split(','):
      degree -= 1
      if degree < 0:
        return False
      if node != '#':
        degree += 2

    return degree == 0
