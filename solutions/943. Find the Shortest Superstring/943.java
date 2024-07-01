class Solution {
  public String shortestSuperstring(String[] A) {
    final int n = A.length;
    // cost[i][j] := the cost to append A[j] after A[i]
    int[][] cost = new int[n][n];

    // Pre-calculate cost array to save time.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cost[i][j] = getCost(A[i], A[j]);
        cost[j][i] = getCost(A[j], A[i]);
      }

    List<Integer> path = new ArrayList<>();
    List<Integer> bestPath = new ArrayList<>();

    minLength = n * 20; // given by problem

    dfs(A, cost, path, bestPath, 0, 0, 0);

    StringBuilder sb = new StringBuilder(A[bestPath.get(0)]);

    for (int k = 1; k < n; ++k) {
      final int i = bestPath.get(k - 1);
      final int j = bestPath.get(k);
      sb.append(A[j].substring(A[j].length() - cost[i][j]));
    }

    return sb.toString();
  }

  private int minLength;

  // Returns the cost to append b after a.
  private int getCost(final String a, final String b) {
    int cost = b.length();
    final int minLength = Math.min(a.length(), b.length());
    for (int k = 1; k <= minLength; ++k)
      if (a.substring(a.length() - k).equals(b.substring(0, k)))
        cost = b.length() - k;
    return cost;
  }

  // used: i-th bit means A[i] is used or not
  private void dfs(String[] A, int[][] cost, List<Integer> path, List<Integer> bestPath, int used,
                   int depth, int currLength) {
    if (currLength >= minLength)
      return;
    if (depth == A.length) {
      minLength = currLength;
      bestPath.clear();
      for (final int node : path) {
        bestPath.add(node);
      }
      return;
    }

    for (int i = 0; i < A.length; ++i) {
      if ((1 << i & used) > 0)
        continue;
      path.add(i);
      final int newLength = depth == 0 ? A[i].length() : currLength + cost[path.get(depth - 1)][i];
      dfs(A, cost, path, bestPath, used | 1 << i, depth + 1, newLength);
      path.remove(path.size() - 1);
    }
  }
}
