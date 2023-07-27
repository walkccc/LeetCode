class Solution {
  public ListNode plusOne(ListNode head) {
    if (head == null)
      return new ListNode(1);
    if (addOne(head) == 1)
      return new ListNode(1, head);
    return head;
  }

  private int addOne(ListNode node) {
    final int carry = node.next == null ? 1 : addOne(node.next);
    final int sum = node.val + carry;
    node.val = sum % 10;
    return sum / 10;
  }
}
