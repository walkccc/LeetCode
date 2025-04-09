class Solution:
  def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
    if not head and m == n:
      return head

    dummy = ListNode(0, head)
    prev = dummy

    for _ in range(m - 1):
      prev = prev.next  # Point to the node before the sublist [m, n].

    tail = prev.next  # Be the tail of the sublist [m, n].

    # Reverse the sublist [m, n] one by one.
    for _ in range(n - m):
      cache = tail.next
      tail.next = cache.next
      cache.next = prev.next
      prev.next = cache

    return dummy.next
