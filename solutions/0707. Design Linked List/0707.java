class MyLinkedList {
  private class ListNode {
    int val;
    ListNode next;
    public ListNode(int val) {
      this.val = val;
      this.next = null;
    }
  }

  public int get(int index) {
    if (index < 0 || index >= length)
      return -1;
    ListNode curr = dummy.next;
    for (int i = 0; i < index; ++i)
      curr = curr.next;
    return curr.val;
  }

  public void addAtHead(int val) {
    ListNode head = dummy.next;
    ListNode node = new ListNode(val);
    node.next = head;
    dummy.next = node;
    ++length;
  }

  public void addAtTail(int val) {
    ListNode curr = dummy;
    while (curr.next != null)
      curr = curr.next;
    curr.next = new ListNode(val);
    ++length;
  }

  public void addAtIndex(int index, int val) {
    if (index > length)
      return;
    ListNode curr = dummy;
    for (int i = 0; i < index; ++i)
      curr = curr.next;
    ListNode cache = curr.next;
    ListNode node = new ListNode(val);
    node.next = cache;
    curr.next = node;
    ++length;
  }

  public void deleteAtIndex(int index) {
    if (index < 0 || index >= length)
      return;
    ListNode curr = dummy;
    for (int i = 0; i < index; ++i)
      curr = curr.next;
    ListNode cache = curr.next;
    curr.next = cache.next;
    --length;
  }

  int length = 0;
  ListNode dummy = new ListNode(0);
}
