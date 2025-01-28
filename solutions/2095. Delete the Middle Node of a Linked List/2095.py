class Solution:
  def deleteMiddle(self, head: ListNode | None) -> ListNode | None:
    dummy = ListNode(0, head)
    slow = dummy
    fast = dummy

    while fast.next and fast.next.next:
      slow = slow.next
      fast = fast.next.next

    # Delete the middle node.
    slow.next = slow.next.next
    return dummy.next
