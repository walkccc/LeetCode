class Solution:
  def sortedListToBST(self, head: ListNode | None) -> TreeNode | None:
    def helper(l: int, r: int) -> TreeNode | None:
      nonlocal head
      if l > r:
        return None

      m = (l + r) // 2

      # Simulate inorder traversal: recursively form the left half.
      left = helper(l, m - 1)

      # Once the left half is traversed, process the current node.
      root = TreeNode(head.val)
      root.left = left

      # Maintain the invariance.
      head = head.next

      # Simulate inorder traversal: recursively form the right half.
      root.right = helper(m + 1, r)
      return root

    return helper(0, self._getLength(head) - 1)

  def _getLength(self, head: ListNode | None) -> int:
    length = 0
    curr = head
    while curr:
      length += 1
      curr = curr.next
    return length
