class Node {
  public int val;
  public Node next;
  public Node down;
  public Node(int val, Node next, Node down) {
    this.val = val;
    this.next = next;
    this.down = down;
  }
}

class Skiplist {
  public boolean search(int target) {
    for (Node node = dummy; node != null; node = node.down) {
      node = advance(node, target);
      if (node.next != null && node.next.val == target)
        return true;
    }
    return false;
  }

  public void add(int num) {
    // Collect nodes that are before the insertion point.
    Deque<Node> nodes = new ArrayDeque<>();
    for (Node node = dummy; node != null; node = node.down) {
      node = advance(node, num);
      nodes.push(node);
    }

    Node down = null;
    boolean shouldInsert = true;
    while (shouldInsert && !nodes.isEmpty()) {
      Node prev = nodes.poll();
      prev.next = new Node(num, prev.next, down);
      down = prev.next;
      shouldInsert = Math.random() < 0.5;
    }

    // Create a topmost new level dummy that points to the existing dummy.
    if (shouldInsert)
      dummy = new Node(-1, null, dummy);
  }

  public boolean erase(int num) {
    boolean found = false;
    for (Node node = dummy; node != null; node = node.down) {
      node = advance(node, num);
      if (node.next != null && node.next.val == num) {
        node.next = node.next.next;
        found = true;
      }
    }
    return found;
  }

  private Node dummy = new Node(-1, null, null);

  private Node advance(Node node, int target) {
    while (node.next != null && node.next.val < target)
      node = node.next;
    return node;
  }
}
