class Solution:
  def findFrequentTreeSum(self, root: TreeNode | None) -> list[int]:
    if not root:
      return []

    count = collections.Counter()

    def dfs(root: TreeNode | None) -> int:
      if not root:
        return 0

      summ = root.val + dfs(root.left) + dfs(root.right)
      count[summ] += 1
      return summ

    dfs(root)
    maxFreq = max(count.values())
    return [summ for summ in count if count[summ] == maxFreq]
