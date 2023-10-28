class Solution {
  public List<Integer> preorder(Node root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Deque<Node> stack = new ArrayDeque<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      root = stack.pop();
      ans.add(root.val);
      for (int i = root.children.size() - 1; i >= 0; --i)
        stack.push(root.children.get(i));
    }

    return ans;
  }
}
