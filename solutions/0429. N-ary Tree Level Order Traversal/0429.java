class Solution {
  public List<List<Integer>> levelOrder(Node root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<Node> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int i = q.size(); i > 0; --i) {
        root = q.poll();
        currLevel.add(root.val);
        for (Node child : root.children)
          q.offer(child);
      }
      ans.add(currLevel);
    }

    return ans;
  }
}