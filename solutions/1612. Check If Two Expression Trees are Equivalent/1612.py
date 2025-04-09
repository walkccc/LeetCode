class Solution:
  def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
    count = collections.Counter()

    def dfs(root: 'Node', add: int) -> None:
      if not root:
        return
      if 'a' <= root.val <= 'z':
        count[root.val] += add
      dfs(root.left, add)
      dfs(root.right, add)

    dfs(root1, 1)
    dfs(root2, -1)
    return all(value == 0 for value in count.values())
