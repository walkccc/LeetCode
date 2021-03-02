class Solution {
 public:
  int minimumSemesters(int N, vector<vector<int>>& relations) {
    vector<int> inDegree(N + 1);
    vector<vector<int>> graph(N + 1);

    // build graph
    for (const auto& r : relations) {
      const int out = r[0];
      const int in = r[1];
      graph[out].push_back(in);
      ++inDegree[in];
    }

    // topology
    int ans = 0;
    queue<int> q;

    for (int i = 1; i <= N; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        const int out = q.front();
        q.pop();
        --N;
        for (const int in : graph[out])
          if (--inDegree[in] == 0)
            q.push(in);
      }
      ++ans;
    }

    return N == 0 ? ans : -1;
  }
};
