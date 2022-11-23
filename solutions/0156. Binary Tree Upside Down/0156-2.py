class Solution:
  def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    prevRoot = None
    prevRightChild = None

    while root:
      nextRoot = root.left  # Cache next root
      root.left = prevRightChild
      prevRightChild = root.right
      root.right = prevRoot
      prevRoot = root  # Record previous root
      root = nextRoot  # Update root

    return prevRoot
