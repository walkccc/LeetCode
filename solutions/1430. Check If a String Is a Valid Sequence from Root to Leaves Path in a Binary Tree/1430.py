class Solution:
  def isValidSequence(self, root: Optional[TreeNode], arr: List[int]) -> bool:
    def isValidSequence(root: Optional[TreeNode], i: int) -> bool:
      if not root:
        return False
      if i == len(arr) - 1:
        return root.val == arr[i] and not root.left and not root.right
      return root.val == arr[i] and (isValidSequence(root.left, i + 1) or isValidSequence(root.right,  i + 1))

    return isValidSequence(root, 0)
