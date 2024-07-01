class Solution:
  def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    inToIndex = {num: i for i, num in enumerate(inorder)}

    def build(preStart: int, preEnd: int, inStart: int, inEnd: int) -> Optional[TreeNode]:
      if preStart > preEnd:
        return None

      rootVal = preorder[preStart]
      rootInIndex = inToIndex[rootVal]
      leftSize = rootInIndex - inStart

      root = TreeNode(rootVal)
      root.left = build(preStart + 1, preStart + leftSize,
                        inStart, rootInIndex - 1)
      root.right = build(preStart + leftSize + 1,
                         preEnd, rootInIndex + 1, inEnd)
      return root

    return build(0, len(preorder) - 1, 0, len(inorder) - 1)
