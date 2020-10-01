class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    unordered_map<string, multiset<string>> graph;

    for (const vector<string>& ticket : tickets)
      graph[ticket[0]].insert(ticket[1]);

    function<void(const string&)> dfs = [&](const string& node) {
      while (graph.count(node) && !graph[node].empty()) {
        const string next = *begin(graph[node]);
        graph[node].erase(begin(graph[node]));
        dfs(next);
      }
      ans.push_back(node);
    };

    dfs("JFK");

    reverse(begin(ans), end(ans));
    return ans;
  }
};