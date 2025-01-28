class Solution {
  public ListNode modifiedList(int[] nums, ListNode head) {
    ListNode dummy = new ListNode(0, head);
    Set<Integer> numsSet = Arrays.stream(nums).boxed().collect(Collectors.toSet());

    for (ListNode curr = dummy; curr.next != null;)
      if (numsSet.contains(curr.next.val))
        curr.next = curr.next.next;
      else
        curr = curr.next;

    return dummy.next;
  }
}
