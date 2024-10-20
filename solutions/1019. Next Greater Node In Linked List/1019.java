class Solution {
  public int[] nextLargerNodes(ListNode head) {
    List<Integer> ans = new ArrayList<>();
    Deque<Integer> stack = new ArrayDeque<>();

    for (; head != null; head = head.next) {
      while (!stack.isEmpty() && head.val > ans.get(stack.peek())) {
        int index = stack.pop();
        ans.set(index, head.val);
      }
      stack.push(ans.size());
      ans.add(head.val);
    }

    while (!stack.isEmpty())
      ans.set(stack.pop(), 0);

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
