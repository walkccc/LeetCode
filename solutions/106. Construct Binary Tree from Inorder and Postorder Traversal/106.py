class Solution:
  def buildTree(
      self,
      inorder: list[int],
      postorder: list[int],
  ) -> TreeNode | None:
    inToIndex = {num: i for i, num in enumerate(inorder)}

    def build(
        inStart: int,
        inEnd: int,
        postStart: int,
        postEnd: int,
    ) -> TreeNode | None:
      if inStart > inEnd:
        return None

      rootVal = postorder[postEnd]
      rootInIndex = inToIndex[rootVal]
      leftSize = rootInIndex - inStart

      root = TreeNode(rootVal)
      root.left = build(inStart, rootInIndex - 1,  postStart,
                        postStart + leftSize - 1)
      root.right = build(rootInIndex + 1, inEnd,  postStart + leftSize,
                         postEnd - 1)
      return root

    return build(0, len(inorder) - 1, 0, len(postorder) - 1)
