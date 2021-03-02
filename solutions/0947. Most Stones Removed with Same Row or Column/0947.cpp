class Solution {
 public:
  int removeStones(vector<vector<int>>& stones) {
    int numOfIslands = 0;
    vector<vector<int>> graph(stones.size());
    unordered_set<int> seen;

    for (int i = 0; i < stones.size(); ++i)
      for (int j = i + 1; j < stones.size(); ++j)
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }

    for (int i = 0; i < stones.size(); ++i)
      if (seen.insert(i).second) {
        dfs(graph, i, seen);
        ++numOfIslands;
      }

    return stones.size() - numOfIslands;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int node,
           unordered_set<int>& seen) {
    for (const int child : graph[node])
      if (seen.insert(child).second)
        dfs(graph, child, seen);
  }
};
