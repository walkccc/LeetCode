class T:
  def __init__(self, isBST: bool = False,
               max: Optional[int] = None,
               min: Optional[int] = None,
               sum: Optional[int] = None):
    self.isBST = isBST
    self.max = max
    self.min = min
    self.sum = sum


class Solution:
  def maxSumBST(self, root: Optional[TreeNode]) -> int:
    self.ans = 0

    def traverse(root: Optional[TreeNode]) -> T:
      if not root:
        return T(True, -math.inf, math.inf, 0)

      left: T = traverse(root.left)
      right: T = traverse(root.right)

      if not left.isBST or not right.isBST:
        return T()
      if root.val <= left.max or root.val >= right.min:
        return T()

      # The `root` is a valid BST.
      summ = root.val + left.sum + right.sum
      self.ans = max(self.ans, summ)
      return T(True, max(root.val, right.max), min(root.val, left.min), summ)

    traverse(root)
    return self.ans
