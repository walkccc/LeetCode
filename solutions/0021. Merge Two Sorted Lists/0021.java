class Solution {
  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if (l1 == null || l2 == null)
      return l1 == null ? l2 : l1;

    if (l1.val > l2.val) {
      ListNode temp = l1;
      l1 = l2;
      l2 = temp;
    }
    l1.next = mergeTwoLists(l1.next, l2);

    return l1;
  }
}
