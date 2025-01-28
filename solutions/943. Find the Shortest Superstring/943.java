class Solution {
  public String shortestSuperstring(String[] words) {
    final int n = words.length;
    // cost[i][j] := the cost to append words[j] after words[i]
    int[][] cost = new int[n][n];

    // Pre-calculate cost array to save time.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cost[i][j] = getCost(words[i], words[j]);
        cost[j][i] = getCost(words[j], words[i]);
      }

    List<Integer> path = new ArrayList<>();
    List<Integer> bestPath = new ArrayList<>();

    minLength = n * 20; // given by problem

    dfs(words, cost, path, bestPath, 0, 0, 0);

    StringBuilder sb = new StringBuilder(words[bestPath.get(0)]);

    for (int k = 1; k < n; ++k) {
      final int i = bestPath.get(k - 1);
      final int j = bestPath.get(k);
      sb.append(words[j].substring(words[j].length() - cost[i][j]));
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

  // used: i-th bit means words[i] is used or not
  private void dfs(String[] words, int[][] cost, List<Integer> path, List<Integer> bestPath,
                   int used, int depth, int currLength) {
    if (currLength >= minLength)
      return;
    if (depth == words.length) {
      minLength = currLength;
      bestPath.clear();
      for (final int node : path) {
        bestPath.add(node);
      }
      return;
    }

    for (int i = 0; i < words.length; ++i) {
      if ((used >> i & 1) == 1)
        continue;
      path.add(i);
      final int newLength =
          depth == 0 ? words[i].length() : currLength + cost[path.get(depth - 1)][i];
      dfs(words, cost, path, bestPath, used | 1 << i, depth + 1, newLength);
      path.remove(path.size() - 1);
    }
  }
}
