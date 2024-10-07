class Solution:
  def pathSum(self, root: TreeNode, summ: int) -> list[list[int]]:
    ans = []

    def dfs(root: TreeNode, summ: int, path: list[int]) -> None:
      if not root:
        return
      if root.val == summ and not root.left and not root.right:
        ans.append(path + [root.val])
        return

      dfs(root.left, summ - root.val, path + [root.val])
      dfs(root.right, summ - root.val, path + [root.val])

    dfs(root, summ, [])
    return ans
