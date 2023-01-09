class Solution {
  public int numSquarefulPerms(int[] A) {
    boolean[] used = new boolean[A.length];
    Arrays.sort(A);
    dfs(A, used, new ArrayList<>());
    return ans;
  }

  private int ans = 0;

  private void dfs(int[] A, boolean[] used, List<Integer> path) {
    if (path.size() > 1 && !isSquare(path.get(path.size() - 1) + path.get(path.size() - 2)))
      return;
    if (path.size() == A.length) {
      ++ans;
      return;
    }

    for (int i = 0; i < A.length; ++i) {
      if (used[i])
        continue;
      if (i > 0 && A[i] == A[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.add(A[i]);
      dfs(A, used, path);
      path.remove(path.size() - 1);
      used[i] = false;
    }
  }

  private boolean isSquare(int num) {
    int root = (int) Math.sqrt(num);
    return root * root == num;
  }
}
