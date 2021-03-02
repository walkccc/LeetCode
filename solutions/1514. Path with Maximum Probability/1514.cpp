class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);  // {a: {b, prob_ab}}
    vector<bool> seen(n);
    vector<double> probs(n);  // probs[i] := max prob to reach node i
    priority_queue<pair<double, int>> pq;  // {prob, node}: max-heap sorted by prob
    pq.push({1.0, start});

    for (int i = 0; i < edges.size(); ++i) {
      const int a = edges[i][0];
      const int b = edges[i][1];
      const double prob = succProb[i];
      graph[a].push_back({b, prob});
      graph[b].push_back({a, prob});
    }

    while (!pq.empty()) {
      const auto [prob, node] = pq.top(); pq.pop();
      if (seen[node]) continue;
      seen[node] = true;
      for (const auto& [nextNode, edgeProb] : graph[node])
        if (probs[nextNode] < prob * edgeProb) {
          probs[nextNode] = prob * edgeProb;
          pq.push({probs[nextNode], nextNode});
        }
    }

    return probs[end];
  }
};
