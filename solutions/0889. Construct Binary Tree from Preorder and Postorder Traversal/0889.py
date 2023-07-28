class Solution:
  def constructFromPrePost(self, pre: List[int], post: List[int]) -> Optional[TreeNode]:
    postToIndex = {num: i for i, num in enumerate(post)}

    def build(preStart: int, preEnd: int, postStart: int, postEnd: int) -> Optional[TreeNode]:
      if preStart > preEnd:
        return None
      if preStart == preEnd:
        return TreeNode(pre[preStart])

      rootVal = pre[preStart]
      leftRootVal = pre[preStart + 1]
      leftRootPostIndex = postToIndex[leftRootVal]
      leftSize = leftRootPostIndex - postStart + 1

      root = TreeNode(rootVal)
      root.left = build(preStart + 1, preStart + leftSize,
                        postStart, leftRootPostIndex)
      root.right = build(preStart + leftSize + 1, preEnd,
                         leftRootPostIndex + 1, postEnd - 1)
      return root

    return build(0, len(pre) - 1, 0, len(post) - 1)
