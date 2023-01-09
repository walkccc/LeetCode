class TrieNode {
  public Map<String, TrieNode> children = new HashMap<>();
  public int value;
  public TrieNode(int value) {
    this.value = value;
  }
}

class FileSystem {
  public boolean createPath(String path, int value) {
    final String[] subpaths = path.split("/");
    TrieNode node = root;

    for (int i = 1; i < subpaths.length - 1; ++i) {
      if (!node.children.containsKey(subpaths[i]))
        return false;
      node = node.children.get(subpaths[i]);
    }

    final String lastSubpath = subpaths[subpaths.length - 1];
    if (node.children.containsKey(lastSubpath))
      return false;
    node.children.put(lastSubpath, new TrieNode(value));
    return true;
  }

  public int get(String path) {
    final String[] subpaths = path.split("/");
    TrieNode node = root;

    for (int i = 1; i < subpaths.length; ++i) {
      if (!node.children.containsKey(subpaths[i]))
        return -1;
      node = node.children.get(subpaths[i]);
    }

    return node.value;
  }

  private TrieNode root = new TrieNode(0);
}
