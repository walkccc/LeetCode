class Solution:
  def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if not head:
      return None

    tail = head

    for _ in range(k):
      # There are less than k nodes in the list, do nothing.
      if not tail:
        return head
      tail = tail.next

    newHead = self._reverse(head, tail)
    head.next = self.reverseKGroup(tail, k)
    return newHead

  def _reverse(self, head: Optional[ListNode], tail: Optional[ListNode]) -> Optional[ListNode]:
    """Reverses [head, tail)."""
    prev = None
    curr = head
    while curr != tail:
      next = curr.next
      curr.next = prev
      prev = curr
      curr = next
    return prev
