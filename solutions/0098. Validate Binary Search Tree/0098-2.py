class Solution:
  def isValidBST(self, root: Optional[TreeNode]) -> bool:
    stack = []
    pred = None

    while root or stack:
      while root:
        stack.append(root)
        root = root.left
      root = stack.pop()
      if pred and pred.val >= root.val:
        return False
      pred = root
      root = root.right

    return True
