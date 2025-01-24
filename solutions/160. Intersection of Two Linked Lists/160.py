class Solution:
  def getIntersectionNode(
      self,
      headA: ListNode,
      headB: ListNode,
  ) -> ListNode | None:
    a = headA
    b = headB

    while a != b:
      a = a.next if a else headB
      b = b.next if b else headA

    return a
