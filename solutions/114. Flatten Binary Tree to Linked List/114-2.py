class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    if not root:
      return

    stack = [root]

    while stack:
      root = stack.pop()
      if root.right:
        stack.append(root.right)
      if root.left:
        stack.append(root.left)
      if stack:
        root.right = stack[-1]
      root.left = None
