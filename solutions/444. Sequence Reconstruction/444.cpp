class Solution {
 public:
  bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    if (seqs.empty())
      return false;

    const int n = org.size();
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);

    // Build the graph.
    for (const vector<int>& seq : seqs) {
      if (seq.size() == 1 && seq[0] < 1 || seq[0] > n)
        return false;
      for (int i = 0; i + 1 < seq.size(); ++i) {
        const int u = seq[i];
        const int v = seq[i + 1];
        if (u < 1 || u > n || v < 1 || v > n)
          return false;
        graph[u - 1].push_back(v - 1);
        ++inDegrees[v - 1];
      }
    }

    // Perform topological sorting.
    queue<int> q;

    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    int i = 0;  // org's index

    while (!q.empty()) {
      if (q.size() > 1)
        return false;
      const int u = q.front();
      q.pop();
      if (u != org[i] - 1)
        return false;
      ++i;
      for (const int v : graph[u])
        if (--inDegrees[v] == 0)
          q.push(v);
    }

    return i == n;
  }
};
