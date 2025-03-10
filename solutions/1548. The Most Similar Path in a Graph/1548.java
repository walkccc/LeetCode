class Solution {
  public List<Integer> mostSimilar(int n, int[][] roads, String[] names, String[] targetPath) {
    this.names = names;
    this.targetPath = targetPath;
    // cost[i][j] := the minimum cost to start from names[i] in path[j]
    this.cost = new int[names.length][targetPath.length];
    // next[i][j] := the best next of names[i] in path[j]
    this.next = new int[names.length][targetPath.length];
    this.graph = new List[n];

    Arrays.stream(cost).forEach(a -> Arrays.fill(a, -1));

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] road : roads) {
      graph[road[0]].add(road[1]);
      graph[road[1]].add(road[0]);
    }

    int minDist = Integer.MAX_VALUE;
    int start = 0;

    // Start from different names
    for (int i = 0; i < names.length; ++i) {
      final int dist = dfs(i, 0);
      if (dist < minDist) {
        minDist = dist;
        start = i;
      }
    }

    List<Integer> ans = new ArrayList<>();

    while (ans.size() < targetPath.length) {
      ans.add(start);
      start = next[start][ans.size() - 1];
    }

    return ans;
  }

  private String[] names;
  private String[] targetPath;
  private int[][] cost;
  private int[][] next;
  private List<Integer>[] graph;

  private int dfs(int nameIndex, int pathIndex) {
    if (cost[nameIndex][pathIndex] != -1)
      return cost[nameIndex][pathIndex];

    final int editDist = names[nameIndex].equals(targetPath[pathIndex]) ? 0 : 1;
    if (pathIndex == targetPath.length - 1)
      return editDist;

    int minDist = Integer.MAX_VALUE;

    for (final int v : graph[nameIndex]) {
      final int dist = dfs(v, pathIndex + 1);
      if (dist < minDist) {
        minDist = dist;
        next[nameIndex][pathIndex] = v;
      }
    }

    return cost[nameIndex][pathIndex] = editDist + minDist;
  }
}
