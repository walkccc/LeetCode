class TrieNode {
  public TrieNode[] children = new TrieNode[2];
  public int count = 0;
}

class Trie {
  public void update(int num, int val) {
    TrieNode node = root;
    for (int i = kHeight; i >= 0; --i) {
      final int bit = (num >> i) & 1;
      if (node.children[bit] == null)
        node.children[bit] = new TrieNode();
      node = node.children[bit];
      node.count += val;
    }
  }

  public int query(int num) {
    int ans = 0;
    TrieNode node = root;
    for (int i = kHeight; i >= 0; --i) {
      final int bit = (num >> i) & 1;
      final int targetBit = bit ^ 1;
      if (node.children[targetBit] != null && node.children[targetBit].count > 0) {
        ans += 1 << i;
        node = node.children[targetBit];
      } else {
        node = node.children[targetBit ^ 1];
      }
    }
    return ans;
  }

  private static final int kHeight = 17;
  TrieNode root = new TrieNode();
}

class Solution {
  public int[] maxGeneticDifference(int[] parents, int[][] queries) {
    final int n = parents.length;
    int[] ans = new int[queries.length];
    int rootVal = -1;
    List<Integer>[] tree = new List[n];

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    // {node: (index, val)}
    Map<Integer, List<Pair<Integer, Integer>>> nodeToQueries = new HashMap<>();
    Trie trie = new Trie();

    for (int i = 0; i < parents.length; ++i)
      if (parents[i] == -1)
        rootVal = i;
      else
        tree[parents[i]].add(i);

    for (int i = 0; i < queries.length; ++i) {
      final int node = queries[i][0];
      final int val = queries[i][1];
      nodeToQueries.putIfAbsent(node, new ArrayList<>());
      nodeToQueries.get(node).add(new Pair<>(i, val));
    }

    dfs(rootVal, trie, tree, nodeToQueries, ans);
    return ans;
  }

  private void dfs(int node, Trie trie, List<Integer>[] tree,
                   Map<Integer, List<Pair<Integer, Integer>>> nodeToQueries, int[] ans) {
    trie.update(node, 1);

    if (nodeToQueries.containsKey(node))
      for (Pair<Integer, Integer> query : nodeToQueries.get(node)) {
        final int i = query.getKey();
        final int val = query.getValue();
        ans[i] = trie.query(val);
      }

    for (final int child : tree[node])
      dfs(child, trie, tree, nodeToQueries, ans);

    trie.update(node, -1);
  }
}
