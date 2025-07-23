class Solution {
  public List<List<Integer>> closestNodes(TreeNode root, List<Integer> queries) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> sortedVals = new ArrayList<>();

    inorder(root, sortedVals);

    for (final int query : queries) {
      final int i = firstGreaterEqual(sortedVals, query);
      // query is presented in the tree, so just use {query, query}.
      if (i != sortedVals.size() && sortedVals.get(i) == query)
        ans.add(Arrays.asList(query, query));
      // query isn't presented in the tree, so find the cloest one if possible.
      else
        ans.add(Arrays.asList(i == 0 ? -1 : sortedVals.get(i - 1),
                              i == sortedVals.size() ? -1 : sortedVals.get(i)));
    }

    return ans;
  }

  // Walks the BST to collect the sorted numbers.
  private void inorder(TreeNode root, List<Integer> sortedVals) {
    if (root == null)
      return;
    inorder(root.left, sortedVals);
    sortedVals.add(root.val);
    inorder(root.right, sortedVals);
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
  }
}
