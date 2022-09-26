class Solution:
  def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
    def helper(l: int, r: int) -> Optional[TreeNode]:
      nonlocal head
      if l > r:
        return None

      m = (l + r) // 2

      # simulate inorder traversal: recursively form the left half
      left = helper(l, m - 1)

      # once left half is traversed, process the current node
      root = TreeNode(head.val)
      root.left = left

      # maintain the invariance
      head = head.next

      # simulate inorder traversal: recursively form the right half
      root.right = helper(m + 1, r)
      return root

    return helper(0, self._getLength(head) - 1)

  def _getLength(self, head: Optional[ListNode]) -> int:
    length = 0
    curr = head
    while curr:
      length += 1
      curr = curr.next
    return length
