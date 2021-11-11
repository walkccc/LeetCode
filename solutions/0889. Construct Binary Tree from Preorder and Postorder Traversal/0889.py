class Solution:
  def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
    def helper(i: int, j: int, n: int) -> TreeNode:
      if n == 0:
        return None

      root = TreeNode(pre[i])
      if n == 1:
        return root

      l = 1  # length of left subtree
      while pre[i + 1] != post[j + l - 1]:
        l += 1

      root.left = helper(i + 1, j, l)
      root.right = helper(i + 1 + l, j + l, n - 1 - l)

      return root

    return helper(0, 0, len(pre))
