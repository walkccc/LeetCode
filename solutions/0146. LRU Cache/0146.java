class Node {
  public int key;
  public int value;

  public Node(int key, int value) {
    this.key = key;
    this.value = value;
  }
}

class LRUCache {
  public LRUCache(int capacity) {
    this.capacity = capacity;
  }

  public int get(int key) {
    if (!keyToNode.containsKey(key))
      return -1;

    Node node = keyToNode.get(key);
    cache.remove(node);
    cache.add(node);
    return node.value;
  }

  public void put(int key, int value) {
    if (keyToNode.containsKey(key)) {
      keyToNode.get(key).value = value;
      get(key);
      return;
    }

    if (cache.size() == capacity) {
      Node lastNode = cache.iterator().next();
      cache.remove(lastNode);
      keyToNode.remove(lastNode.key);
    }

    Node node = new Node(key, value);
    cache.add(node);
    keyToNode.put(key, node);
  }

  private int capacity;
  private Set<Node> cache = new LinkedHashSet<>();
  private Map<Integer, Node> keyToNode = new HashMap<>();
}
