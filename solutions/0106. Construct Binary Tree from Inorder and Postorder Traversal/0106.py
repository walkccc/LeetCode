class Solution:
  def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
    inorderToIndex = {num: i for i, num in enumerate(inorder)}

    def helper(iL: int, iR: int, pL: int, pR: int) -> TreeNode:
      if iL > iR:
        return None

      i = inorderToIndex[postorder[pR]]
      curr = TreeNode(postorder[pR])
      curr.left = helper(iL, i - 1, pL, pL + i - iL - 1)
      curr.right = helper(i + 1, iR, pL + i - iL, pR - 1)

      return curr

    return helper(0, len(inorder) - 1, 0, len(postorder) - 1)
