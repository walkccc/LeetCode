class Solution {
  public int closestMeetingNode(int[] edges, int node1, int node2) {
    final int kMax = 10000;
    final int[] dist1 = getDist(edges, node1);
    final int[] dist2 = getDist(edges, node2);
    int minDist = kMax;
    int ans = -1;

    for (int i = 0; i < edges.length; ++i)
      if (Math.min(dist1[i], dist2[i]) >= 0) {
        final int maxDist = Math.max(dist1[i], dist2[i]);
        if (maxDist < minDist) {
          minDist = maxDist;
          ans = i;
        }
      }

    return ans;
  }

  private int[] getDist(int[] edges, int u) {
    int[] dist = new int[edges.length];
    Arrays.fill(dist, -1);
    int d = 0;
    while (u != -1 && dist[u] == -1) {
      dist[u] = d++;
      u = edges[u];
    }
    return dist;
  }
}
