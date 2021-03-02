class Solution:
  def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    if not l1 or not l2:
      return l1 if l1 else l2

    if l1.val > l2.val:
      l1, l2 = l2, l1
    l1.next = self.mergeTwoLists(l1.next, l2)

    return l1
