class Solution:
  def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
    ans = []

    def dfs(root: TreeNode, sum: int, path: List[int]) -> None:
      if root is None:
        return
      if root.val == sum and root.left is None and root.right is None:
        ans.append(path + [root.val])
        return

      dfs(root.left, sum - root.val, path + [root.val])
      dfs(root.right, sum - root.val, path + [root.val])

    dfs(root, sum, [])

    return ans
