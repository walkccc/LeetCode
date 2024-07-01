class Solution:
  def generateTrees(self, n: int) -> List[TreeNode]:
    if n == 0:
      return []

    def generateTrees(mini: int, maxi: int) -> List[Optional[int]]:
      if mini > maxi:
        return [None]

      ans = []

      for i in range(mini, maxi + 1):
        for left in generateTrees(mini, i - 1):
          for right in generateTrees(i + 1, maxi):
            ans.append(TreeNode(i))
            ans[-1].left = left
            ans[-1].right = right

      return ans

    return generateTrees(1, n)
