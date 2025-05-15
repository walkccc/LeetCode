class Solution {
  public int minimumOperations(TreeNode root) {
    int ans = 0;
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    // e.g. vals = [7, 6, 8, 5]
    // [2, 1, 3, 0]: Initialize the ids based on the order of vals.
    // [3, 1, 2, 0]: Swap 2 with 3, so 2 is in the right place (i == ids[i]).
    // [0, 1, 2, 3]: Swap 3 with 0, so 3 is in the right place.
    while (!q.isEmpty()) {
      List<Integer> vals = new ArrayList<>();
      List<Integer> ids = new ArrayList<>();
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        vals.add(node.val);
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      for (int i = 0; i < vals.size(); ++i)
        ids.add(i);
      Collections.sort(ids, (i, j) -> vals.get(i) - vals.get(j));
      for (int i = 0; i < ids.size(); ++i)
        for (; ids.get(i) != i; ++ans)
          swap(ids, i, ids.get(i));
    }

    return ans;
  }

  private void swap(List<Integer> ids, int i, int j) {
    final int temp = ids.get(i);
    ids.set(i, ids.get(j));
    ids.set(j, temp);
  }
}
