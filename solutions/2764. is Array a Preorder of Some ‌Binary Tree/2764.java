class Solution {
  public boolean isPreorder(List<List<Integer>> nodes) {
    Deque<Integer> stack = new ArrayDeque<>(); // Stores `id`s.

    for (List<Integer> node : nodes) {
      final int id = node.get(0);
      final int parentId = node.get(1);
      if (parentId == -1) {
        stack.push(id);
        continue;
      }
      while (!stack.isEmpty() && stack.peek() != parentId)
        stack.pop();
      if (stack.isEmpty())
        return false;
      stack.push(id);
    }

    return true;
  }
}
