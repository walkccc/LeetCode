class Solution:
  def countUnivalSubtrees(self, root: TreeNode | None) -> int:
    ans = 0

    def isUnival(root: TreeNode | None, val: int) -> bool:
      nonlocal ans
      if not root:
        return True

      if isUnival(root.left, root.val) & isUnival(root.right, root.val):
        ans += 1
        return root.val == val

      return False

    isUnival(root, math.inf)
    return ans
