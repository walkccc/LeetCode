class Solution:
  def removeNodes(self, head: ListNode | None) -> ListNode | None:
    if not head:
      return None
    head.next = self.removeNodes(head.next)
    return head.next if head.next and head.val < head.next.val else head
