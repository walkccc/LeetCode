class Solution {
  public int[] nodesBetweenCriticalPoints(ListNode head) {
    int minDistance = Integer.MAX_VALUE;
    int firstMaIndex = -1;
    int prevMaIndex = -1;
    int index = 1;
    ListNode prev = head;      // point to index 0
    ListNode curr = head.next; // point to index 1

    while (curr.next != null) {
      if (curr.val > prev.val && curr.val > curr.next.val ||
          curr.val < prev.val && curr.val < curr.next.val) {
        if (firstMaIndex == -1) // only assign once
          firstMaIndex = index;
        if (prevMaIndex != -1)
          minDistance = Math.min(minDistance, index - prevMaIndex);
        prevMaIndex = index;
      }
      prev = curr;
      curr = curr.next;
      ++index;
    }

    if (minDistance == Integer.MAX_VALUE)
      return new int[] {-1, -1};
    return new int[] {minDistance, prevMaIndex - firstMaIndex};
  }
}
