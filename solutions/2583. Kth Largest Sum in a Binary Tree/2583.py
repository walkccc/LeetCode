class Solution:
  def kthLargestLevelSum(self, root: TreeNode | None, k: int) -> int:
    levelSums = []

    def dfs(root: TreeNode | None, level: int) -> None:
      if not root:
        return
      if len(levelSums) == level:
        levelSums.append(0)
      levelSums[level] += root.val
      dfs(root.left, level + 1)
      dfs(root.right, level + 1)

    dfs(root, 0)
    if len(levelSums) < k:
      return -1

    return sorted(levelSums, reverse=True)[k - 1]
