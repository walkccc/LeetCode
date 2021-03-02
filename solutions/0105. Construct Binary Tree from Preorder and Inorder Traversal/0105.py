class Solution:
  def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
    inorderToIndex = {num: i for i, num in enumerate(inorder)}

    def helper(pL: int, pR: int, iL: int, iR: int) -> TreeNode:
      if pL > pR:
        return None

      i = inorderToIndex[preorder[pL]]
      curr = TreeNode(preorder[pL])
      curr.left = helper(pL + 1, pL + i - iL, iL, i - 1)
      curr.right = helper(pL + i - iL + 1, pR, i + 1, iR)

      return curr

    return helper(0, len(preorder) - 1, 0, len(inorder) - 1)
