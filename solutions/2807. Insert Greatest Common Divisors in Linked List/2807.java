class Solution {
  public ListNode insertGreatestCommonDivisors(ListNode head) {
    for (ListNode curr = head; curr.next != null;) {
      ListNode inserted = new ListNode(gcd(curr.val, curr.next.val), curr.next);
      curr.next = inserted;
      curr = inserted.next;
    }
    return head;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
