class Solution:
  def findTilt(self, root: TreeNode | None) -> int:
    ans = 0

    def summ(root: TreeNode | None) -> None:
      nonlocal ans
      if not root:
        return 0

      l = summ(root.left)
      r = summ(root.right)
      ans += abs(l - r)
      return root.val + l + r

    summ(root)
    return ans
