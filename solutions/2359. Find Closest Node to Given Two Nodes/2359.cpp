class Solution {
 public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    constexpr int kMax = 10000;
    const vector<int> dist1 = getDist(edges, node1);
    const vector<int> dist2 = getDist(edges, node2);
    int minDist = kMax;
    int ans = -1;

    for (int i = 0; i < edges.size(); ++i)
      if (min(dist1[i], dist2[i]) >= 0) {
        const int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minDist) {
          minDist = maxDist;
          ans = i;
        }
      }

    return ans;
  }

 private:
  vector<int> getDist(const vector<int>& edges, int u) {
    vector<int> dist(edges.size(), -1);
    int d = 0;
    while (u != -1 && dist[u] == -1) {
      dist[u] = d++;
      u = edges[u];
    }
    return dist;
  }
};
