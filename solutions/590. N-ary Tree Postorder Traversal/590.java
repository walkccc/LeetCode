class Solution {
  public List<Integer> postorder(Node root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Deque<Node> stack = new ArrayDeque<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      root = stack.pop();
      ans.add(root.val);
      for (Node child : root.children)
        stack.push(child);
    }

    Collections.reverse(ans);
    return ans;
  }
}
