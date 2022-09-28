class TrieNode implements Comparable<TrieNode> {
  public TrieNode[] children = new TrieNode[128];
  public String s = null;
  public int time = 0;
  public List<TrieNode> top3 = new ArrayList<>();

  public int compareTo(TrieNode o) {
    if (this.time == o.time)
      return this.s.compareTo(o.s);
    return o.time - this.time;
  }

  public void update(TrieNode node) {
    if (!this.top3.contains(node))
      this.top3.add(node);
    Collections.sort(top3);
    if (top3.size() > 3)
      top3.remove(top3.size() - 1);
  }
}

class AutocompleteSystem {
  public AutocompleteSystem(String[] sentences, int[] times) {
    for (int i = 0; i < sentences.length; ++i)
      insert(sentences[i], times[i]);
  }

  public List<String> input(char c) {
    if (c == '#') {
      insert(sb.toString(), 1);
      curr = root;
      sb = new StringBuilder();
      return new ArrayList<>();
    }

    sb.append(c);

    if (curr != null)
      curr = curr.children[c];
    if (curr == null)
      return new ArrayList<>();

    List<String> ans = new ArrayList<>();

    for (TrieNode node : curr.top3)
      ans.add(node.s);

    return ans;
  }

  private TrieNode root = new TrieNode();
  private TrieNode curr = root;
  private StringBuilder sb = new StringBuilder();

  private void insert(final String s, int time) {
    TrieNode node = root;
    for (final char c : s.toCharArray()) {
      if (node.children[c] == null)
        node.children[c] = new TrieNode();
      node = node.children[c];
    }
    node.s = s;
    node.time += time;

    // walk the path again and update the node with leaf node
    TrieNode leaf = node;
    node = root;
    for (final char c : s.toCharArray()) {
      node = node.children[c];
      node.update(leaf);
    }
  }
}
