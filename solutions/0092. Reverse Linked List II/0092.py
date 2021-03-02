class Solution:
  def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
    if not head and m == n:
      return head

    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    for i in range(m - 1):
      prev = prev.next  # point to the node before the sublist [m, n]

    tail = prev.next  # will be the tail of the sublist [m, n]

    # reverse the sublist [m, n] one by one
    for i in range(n - m):
      cache = tail.next
      tail.next = cache.next
      cache.next = prev.next
      prev.next = cache

    return dummy.next
