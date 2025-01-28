class Solution:
  def largestValues(self, root: TreeNode | None) -> list[int]:
    ans = []

    def dfs(root: TreeNode | None, depth: int) -> None:
      if not root:
        return
      if depth + 1 > len(ans):
        ans.append(root.val)
      else:
        ans[depth] = max(ans[depth], root.val)

      dfs(root.left, depth + 1)
      dfs(root.right, depth + 1)

    dfs(root, 0)
    return ans
