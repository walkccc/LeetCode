class Solution {
  public Node cloneGraph(Node node) {
    if (node == null)
      return null;

    Queue<Node> q = new ArrayDeque<>(Arrays.asList(node));
    Map<Node, Node> map = new HashMap<>();
    map.put(node, new Node(node.val));

    while (!q.isEmpty()) {
      Node u = q.poll();
      for (Node v : u.neighbors) {
        if (!map.containsKey(v)) {
          map.put(v, new Node(v.val));
          q.offer(v);
        }
        map.get(u).neighbors.add(map.get(v));
      }
    }

    return map.get(node);
  }
}
