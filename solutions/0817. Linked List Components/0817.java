class Solution {
  public int numComponents(ListNode head, int[] G) {
    int ans = 0;
    Set<Integer> setG = new HashSet<>();

    for (final int g : G)
      setG.add(g);

    for (; head != null; head = head.next)
      if (setG.contains(head.val) && (head.next == null || !setG.contains(head.next.val)))
        ++ans;

    return ans;
  }
}
