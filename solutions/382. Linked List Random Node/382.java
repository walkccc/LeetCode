class Solution {
  /**
   * @param head The linked list's head. Note that the head is guaranteed to be
   *             not null, so it contains at least one node.
   */
  public Solution(ListNode head) {
    this.head = head;
  }

  /** Returns a random node's value. */
  public int getRandom() {
    int res = -1;
    int i = 1;

    for (ListNode curr = head; curr != null; curr = curr.next, ++i)
      if (rand.nextInt(i) == i - 1)
        res = curr.val;

    return res;
  }

  private ListNode head;
  private Random rand = new Random();
}
