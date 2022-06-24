class Solution:
  def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
    A = []

    # construct the array
    curr = head
    while curr:
      A.append(curr.val)
      curr = curr.next

    def helper(l: int, r: int) -> Optional[TreeNode]:
      if l > r:
        return None

      m = (l + r) // 2
      root = TreeNode(A[m])
      root.left = helper(l, m - 1)
      root.right = helper(m + 1, r)
      return root

    return helper(0, len(A) - 1)
