class Solution:
  def getTargetCopy(
      self,
      original: TreeNode,
      cloned: TreeNode,
      target: TreeNode,
  ) -> TreeNode:
    ans = None

    def dfs(original: TreeNode, cloned: TreeNode) -> None:
      nonlocal ans
      if ans:
        return
      if not original:
        return
      if original == target:
        ans = cloned
        return

      dfs(original.left, cloned.left)
      dfs(original.right, cloned.right)

    dfs(original, cloned)
    return ans
