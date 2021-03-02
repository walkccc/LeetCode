class Solution:
  def removeElements(self, head: ListNode, val: int) -> ListNode:
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    while head:
      if head.val != val:
        prev.next = head
        prev = prev.next
      head = head.next
    prev.next = None

    return dummy.next
