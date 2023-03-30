class Solution {
  public List<List<Integer>> levelOrder(Node root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<Node> q = new ArrayDeque<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int sz = q.size(); sz > 0; --sz) {
        Node node = q.poll();
        currLevel.add(node.val);
        for (Node child : node.children)
          q.offer(child);
      }
      ans.add(currLevel);
    }

    return ans;
  }
}
