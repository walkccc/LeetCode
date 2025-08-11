class Solution:
  def sumRootToLeaf(self, root: TreeNode | None) -> int:
    ans = 0

    def dfs(root: TreeNode | None, val: int) -> None:
      nonlocal ans
      if not root:
        return
      val = val * 2 + root.val
      if not root.left and not root.right:
        ans += val
      dfs(root.left, val)
      dfs(root.right, val)

    dfs(root, 0)
    return ans
