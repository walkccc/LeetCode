class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses);
    vector<vector<int>> graph(numCourses);

    // build graph
    for (const auto& p : prerequisites) {
      const int out = p[1];
      const int in = p[0];
      graph[out].push_back(in);
      ++inDegree[in];
    }

    // topology
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int out = q.front();
      q.pop();
      ans.push_back(out);
      for (const int in : graph[out])
        if (--inDegree[in] == 0)
          q.push(in);
    }

    return ans.size() == numCourses ? ans : vector<int>();
  }
};
