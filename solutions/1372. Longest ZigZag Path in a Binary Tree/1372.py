class T:
  def __init__(self, leftMax: int, rightMax: int, subtreeMax: int):
    self.leftMax = leftMax
    self.rightMax = rightMax
    self.subtreeMax = subtreeMax


class Solution:
  def longestZigZag(self, root: Optional[TreeNode]) -> int:
    def dfs(root: Optional[TreeNode]) -> T:
      if not root:
        return T(-1, -1, -1)
      left = dfs(root.left)
      right = dfs(root.right)
      leftZigZag = left.rightMax + 1
      rightZigZag = right.leftMax + 1
      subtreeMax = max(leftZigZag, rightZigZag,
                       left.subtreeMax, right.subtreeMax)
      return T(leftZigZag, rightZigZag, subtreeMax)

    return dfs(root).subtreeMax
