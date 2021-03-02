class Solution:
  def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
    def dfs(root: TreeNode) -> int:
      if root is None:
        return 0

      sum = root.val + dfs(root.left) + dfs(root.right)
      count[sum] += 1

      return sum

    if root is None:
      return []

    count = Counter()
    dfs(root)
    maxFreq = max(count.values())

    return [sum for sum in count if count[sum] == maxFreq]
