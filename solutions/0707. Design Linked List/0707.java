class MyLinkedList {
  public int get(int index) {
    if (index < 0 || index >= length)
      return -1;
    ListNode curr = dummy.next;
    for (int i = 0; i < index; ++i)
      curr = curr.next;
    return curr.val;
  }

  public void addAtHead(int val) {
    ListNode curr = dummy.next;
    dummy.next = new ListNode(val);
    dummy.next.next = curr;
    ++length;
  }

  public void addAtTail(int val) {
    ListNode curr = dummy.next;
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
    ListNode temp = curr.next;
    curr.next = new ListNode(val);
    curr.next.next = temp;
    ++length;
  }

  public void deleteAtIndex(int index) {
    if (index < 0 || index >= length)
      return;
    ListNode curr = dummy;
    for (int i = 0; i < index; ++i)
      curr = curr.next;
    ListNode temp = curr.next;
    curr.next = temp.next;
    --length;
  }

  private class ListNode {
    int val;
    ListNode next;

    public ListNode(int val) {
      this.val = val;
    }
  }

  int length = 0;
  ListNode dummy = new ListNode(0);
}