class Solution {
  public List<List<Integer>> levelOrder(Node root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<Node> q = new LinkedList<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int size = q.size(); size > 0; --size) {
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
