class Solution:
  def mergeNodes(self, head: ListNode | None) -> ListNode | None:
    if not head:
      return None
    if not head.next.val:
      node = ListNode(head.val)
      node.next = self.mergeNodes(head.next.next)
      return node

    next = self.mergeNodes(head.next)
    next.val += head.val
    return next
