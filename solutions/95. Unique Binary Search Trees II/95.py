class Solution:
  def generateTrees(self, n: int) -> list[TreeNode]:
    if n == 0:
      return []

    def generateTrees(mn: int, mx: int) -> list[int | None]:
      if mn > mx:
        return [None]

      ans = []

      for i in range(mn, mx + 1):
        for left in generateTrees(mn, i - 1):
          for right in generateTrees(i + 1, mx):
            ans.append(TreeNode(i))
            ans[-1].left = left
            ans[-1].right = right

      return ans

    return generateTrees(1, n)
