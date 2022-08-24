class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    if not root:
      return

    while root:
      if root.left:
        # find the rightmost root
        rightmost = root.left
        while rightmost.right:
          rightmost = rightmost.right
        # rewire the connections
        rightmost.right = root.right
        root.right = root.left
        root.left = None
      # move on to the right side of the tree
      root = root.right
