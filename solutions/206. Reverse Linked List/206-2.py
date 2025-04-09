class Solution:
  def reverseList(self, head: ListNode | None) -> ListNode | None:
    prev = None
    curr = head

    while curr:
      next = curr.next
      curr.next = prev
      prev = curr
      curr = next

    return prev
