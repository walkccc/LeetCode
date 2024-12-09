class Solution:
  def sortedListToBST(self, head: ListNode | None) -> TreeNode | None:
    A = []

    # Construct the array.
    curr = head
    while curr:
      A.append(curr.val)
      curr = curr.next

    def helper(l: int, r: int) -> TreeNode | None:
      if l > r:
        return None

      m = (l + r) // 2
      root = TreeNode(A[m])
      root.left = helper(l, m - 1)
      root.right = helper(m + 1, r)
      return root

    return helper(0, len(A) - 1)
