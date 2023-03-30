class Solution {
  public int numComponents(ListNode head, int[] nums) {
    int ans = 0;
    Set<Integer> setNums = new HashSet<>();

    for (final int g : nums)
      setNums.add(g);

    for (; head != null; head = head.next)
      if (setNums.contains(head.val) && (head.next == null || !setNums.contains(head.next.val)))
        ++ans;

    return ans;
  }
}
