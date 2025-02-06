class Solution:
  def plusOne(self, head: ListNode) -> ListNode:
    dummy = ListNode(0)
    curr = dummy
    dummy.next = head

    while head:
      if head.val != 9:
        curr = head
      head = head.next
    # `curr` now points to the rightmost non-9 node.

    curr.val += 1
    while curr.next:
      curr.next.val = 0
      curr = curr.next

    return dummy.next if dummy.val == 0 else dummy
