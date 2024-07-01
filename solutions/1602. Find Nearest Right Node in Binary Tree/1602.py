class Solution:
  def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> Optional[TreeNode]:
    ans = None
    targetDepth = -1

    def dfs(root: TreeNode, depth: int) -> None:
      nonlocal ans
      nonlocal targetDepth
      if not root:
        return
      if root == u:
        targetDepth = depth
        return
      if depth == targetDepth and not ans:
        ans = root
        return
      dfs(root.left, depth + 1)
      dfs(root.right, depth + 1)

    dfs(root, 0)
    return ans
