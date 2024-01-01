class Solution {
  public ListNode deleteNodes(ListNode head, int m, int n) {
    ListNode curr = head;
    ListNode prev = null; // prev.next == curr

    while (curr != null) {
      // Set the m-th node as `prev`.
      for (int i = 0; i < m & curr != null; ++i) {
        prev = curr;
        curr = curr.next;
      }
      // Set the (m + n + 1)-th node as `curr`.
      for (int i = 0; i < n && curr != null; ++i)
        curr = curr.next;
      // Delete the nodes [m + 1..n - 1].
      prev.next = curr;
    }

    return head;
  }
}
