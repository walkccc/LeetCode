class Solution:
  def pathSum(self, root: TreeNode, summ: int) -> List[List[int]]:
    ans = []

    def dfs(root: TreeNode, summ: int, path: List[int]) -> None:
      if root is None:
        return
      if root.val == summ and root.left is None and root.right is None:
        ans.append(path + [root.val])
        return

      dfs(root.left, summ - root.val, path + [root.val])
      dfs(root.right, summ - root.val, path + [root.val])

    dfs(root, summ, [])
    return ans
