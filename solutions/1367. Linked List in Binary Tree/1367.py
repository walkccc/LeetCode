class Solution:
  def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
    if not root:
      return False
    return self._isContinuousSubPath(head, root) or \
        self.isSubPath(head, root.left) or \
        self.isSubPath(head, root.right)

  def _isContinuousSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
    if not head:
      return True
    if not root:
      return False
    return head.val == root.val and \
        (self._isContinuousSubPath(head.next, root.left)
         or self._isContinuousSubPath(head.next, root.right))
