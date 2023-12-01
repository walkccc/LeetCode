class Solution:
  def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0)
    prev = dummy  # the last and thus largest of the sorted list

    while head:  # the current inserting node
      next = head.next  # Cache the next inserting node.
      if prev.val >= head.val:
        prev = dummy  # Move the `prev` to the front.
      while prev.next and prev.next.val < head.val:
        prev = prev.next
      head.next = prev.next
      prev.next = head
      head = next  # Update the current inserting node.

    return dummy.next
