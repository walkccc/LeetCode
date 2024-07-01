class TrieNode {
  public Map<String, TrieNode> children = new HashMap<>();
  public boolean deleted = false;
}

class Solution {
  public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, List<TrieNode>> subtreeToNodes = new HashMap<>();

    Collections.sort(paths, (a, b) -> {
      for (int i = 0; i < Math.min(a.size(), b.size()); ++i) {
        final int c = a.get(i).compareTo(b.get(i));
        if (c != 0)
          return c;
      }
      return Integer.compare(a.size(), b.size());
    });

    for (List<String> path : paths) {
      TrieNode node = root;
      for (final String s : path) {
        node.children.putIfAbsent(s, new TrieNode());
        node = node.children.get(s);
      }
    }

    buildSubtreeToRoots(root, subtreeToNodes);

    for (List<TrieNode> nodes : subtreeToNodes.values())
      if (nodes.size() > 1)
        for (TrieNode node : nodes)
          node.deleted = true;

    constructPath(root, new ArrayList<>(), ans);
    return ans;
  }

  private TrieNode root = new TrieNode();

  private StringBuilder buildSubtreeToRoots(TrieNode node,
                                            Map<String, List<TrieNode>> subtreeToNodes) {
    StringBuilder sb = new StringBuilder("(");
    for (final String s : node.children.keySet()) {
      TrieNode child = node.children.get(s);
      sb.append(s).append(buildSubtreeToRoots(child, subtreeToNodes));
    }
    sb.append(")");
    final String subtree = sb.toString();
    if (!subtree.equals("()")) {
      subtreeToNodes.putIfAbsent(subtree, new ArrayList<>());
      subtreeToNodes.get(subtree).add(node);
    }
    return sb;
  }

  private void constructPath(TrieNode node, List<String> path, List<List<String>> ans) {
    for (final String s : node.children.keySet()) {
      TrieNode child = node.children.get(s);
      if (!child.deleted) {
        path.add(s);
        constructPath(child, path, ans);
        path.remove(path.size() - 1);
      }
    }
    if (!path.isEmpty())
      ans.add(new ArrayList<>(path));
  }
}
