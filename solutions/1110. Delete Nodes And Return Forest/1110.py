class Solution:
  def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
    ans = []
    toDeleteSet = set(to_delete)

    def dfs(root: TreeNode, isRoot: bool) -> TreeNode:
      if not root:
        return None

      deleted = root.val in toDeleteSet
      if isRoot and not deleted:
        ans.append(root)

      # if root is deleted, both children have the possibility to be a new root
      root.left = dfs(root.left, deleted)
      root.right = dfs(root.right, deleted)
      return None if deleted else root

    dfs(root, True)
    return ans
