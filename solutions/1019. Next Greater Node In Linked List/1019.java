class Solution {
  public int[] nextLargerNodes(ListNode head) {
    List<Integer> ans = new ArrayList<>();
    Stack<Integer> stack = new Stack<>();

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

    return ans.stream().mapToInt(i -> i).toArray();
  }
}
