class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    Deque<ListNode> stack1 = new ArrayDeque<>();
    Deque<ListNode> stack2 = new ArrayDeque<>();

    while (l1 != null) {
      stack1.push(l1);
      l1 = l1.next;
    }

    while (l2 != null) {
      stack2.push(l2);
      l2 = l2.next;
    }

    ListNode head = null;
    int carry = 0;

    while (carry > 0 || !stack1.isEmpty() || !stack2.isEmpty()) {
      if (!stack1.isEmpty())
        carry += stack1.pop().val;
      if (!stack2.isEmpty())
        carry += stack2.pop().val;
      ListNode node = new ListNode(carry % 10);
      node.next = head;
      head = node;
      carry /= 10;
    }

    return head;
  }
}
