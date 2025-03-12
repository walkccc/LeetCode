class Solution {
  public int longestCycle(int[] edges) {
    int ans = -1;
    int time = 1;
    int[] timeVisited = new int[edges.length];

    for (int i = 0; i < edges.length; ++i) {
      if (timeVisited[i] > 0)
        continue;
      final int startTime = time;
      int u = i;
      while (u != -1 && timeVisited[u] == 0) {
        timeVisited[u] = time++;
        u = edges[u]; // Move to the next node.
      }
      if (u != -1 && timeVisited[u] >= startTime)
        ans = Math.max(ans, time - timeVisited[u]);
    }

    return ans;
  }
}
