class Solution:
  def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    prevRoot = None
    prevRightChild = None

    while root:
      nextRoot = root.left  # cache next root
      root.left = prevRightChild
      prevRightChild = root.right
      root.right = prevRoot
      prevRoot = root  # record previous root
      root = nextRoot  # update root

    return prevRoot
