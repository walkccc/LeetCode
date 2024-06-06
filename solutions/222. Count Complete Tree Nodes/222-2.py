class Solution:
  def countNodes(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0

    left = root
    right = root
    heightL = 0
    heightR = 0

    while left:
      heightL += 1
      left = left.left

    while right:
      heightR += 1
      right = right.right

    if heightL == heightR:  # `root` is a complete tree.
      return pow(2, heightL) - 1
    return 1 + self.countNodes(root.left) + self.countNodes(root.right)
