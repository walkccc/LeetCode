class Solution {
  public List<List<Integer>> verticalTraversal(TreeNode root) {
    List<List<Integer>> ans = new ArrayList<>();
    TreeMap<Integer, List<int[]>> xToNodes = new TreeMap<>();

    dfs(root, 0, 0, xToNodes);

    for (List<int[]> nodes : xToNodes.values()) {
      Collections.sort(nodes, new Comparator<int[]>() {
        @Override
        public int compare(int[] n1, int[] n2) {
          return n1[0] == n2[0] ? n1[1] - n2[1] : n2[0] - n1[0];
        }
      });
      List<Integer> vals = new ArrayList<>();
      for (int[] node : nodes)
        vals.add(node[1]);
      ans.add(vals);
    }

    return ans;
  }

  private void dfs(TreeNode root, int x, int y, TreeMap<Integer, List<int[]>> xToNodes) {
    if (root == null)
      return;

    if (!xToNodes.containsKey(x))
      xToNodes.put(x, new ArrayList<>());
    xToNodes.get(x).add(new int[] { y, root.val });
    dfs(root.left, x - 1, y - 1, xToNodes);
    dfs(root.right, x + 1, y - 1, xToNodes);
  }
}