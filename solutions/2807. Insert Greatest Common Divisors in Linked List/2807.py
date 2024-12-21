class Solution:
  def insertGreatestCommonDivisors(
      self, head: ListNode | None
  ) -> ListNode | None:
    curr = head
    while curr.next:
      inserted = ListNode(math.gcd(curr.val, curr.next.val), curr.next)
      curr.next = inserted
      curr = inserted.next
    return head
