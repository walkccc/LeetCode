class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    unordered_map<string, multiset<string>> graph;

    for (const vector<string>& ticket : tickets)
      graph[ticket[0]].insert(ticket[1]);

    dfs(graph, "JFK", ans);
    ranges::reverse(ans);
    return ans;
  }

 private:
  void dfs(unordered_map<string, multiset<string>>& graph, const string& u,
           vector<string>& ans) {
    while (graph.contains(u) && !graph[u].empty()) {
      const string v = *graph[u].begin();
      graph[u].erase(graph[u].begin());
      dfs(graph, v, ans);
    }
    ans.push_back(u);
  }
};
