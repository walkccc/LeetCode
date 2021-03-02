class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    unordered_map<string, multiset<string>> graph;

    for (const auto& ticket : tickets)
      graph[ticket[0]].insert(ticket[1]);

    dfs(graph, "JFK", ans);

    reverse(begin(ans), end(ans));
    return ans;
  }

 private:
  void dfs(unordered_map<string, multiset<string>>& graph, const string& node,
           vector<string>& ans) {
    while (graph.count(node) && !graph[node].empty()) {
      const string next = *begin(graph[node]);
      graph[node].erase(begin(graph[node]));
      dfs(graph, next, ans);
    }
    ans.push_back(node);
  }
};
