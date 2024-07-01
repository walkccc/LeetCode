class Solution {
  public boolean isPalindrome(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;

    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    if (fast != null)
      slow = slow.next;
    slow = reverseList(slow);

    while (slow != null) {
      if (slow.val != head.val)
        return false;
      slow = slow.next;
      head = head.next;
    }

    return true;
  }

  private ListNode reverseList(ListNode head) {
    ListNode prev = null;

    while (head != null) {
      ListNode next = head.next;
      head.next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
}
