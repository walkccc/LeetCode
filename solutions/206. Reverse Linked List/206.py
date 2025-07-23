class Solution:
  def reverseList(self, head: ListNode | None) -> ListNode | None:
    if not head or not head.next:
      return head

    newHead = self.reverseList(head.next)
    head.next.next = head
    head.next = None
    return newHead
