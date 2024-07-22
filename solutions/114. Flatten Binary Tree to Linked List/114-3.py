class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    if not root:
      return

    while root:
      if root.left:
        # Find the rightmost root
        rightmost = root.left
        while rightmost.right:
          rightmost = rightmost.right
        # Rewire the connections
        rightmost.right = root.right
        root.right = root.left
        root.left = None
      # Move on to the right side of the tree
      root = root.right
