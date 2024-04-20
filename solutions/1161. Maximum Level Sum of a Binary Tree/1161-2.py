class Solution:
  def maxLevelSum(self, root: Optional[TreeNode]) -> int:
    # levelSums[i] := the sum of level (i + 1) (1-indexed)
    levelSums = []

    def dfs(root: Optional[TreeNode], level: int) -> None:
      if not root:
        return
      if len(levelSums) == level:
        levelSums.append(0)
      levelSums[level] += root.val
      dfs(root.left, level + 1)
      dfs(root.right, level + 1)

    dfs(root, 0)
    return 1 + levelSums.index(max(levelSums))
