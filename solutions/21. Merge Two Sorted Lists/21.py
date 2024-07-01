class Solution:
  def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    if not list1 or not list2:
      return list1 if list1 else list2
    if list1.val > list2.val:
      list1, list2 = list2, list1
    list1.next = self.mergeTwoLists(list1.next, list2)
    return list1
