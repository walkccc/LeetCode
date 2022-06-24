class Solution {
 public:
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    vector<string> ans;
    unordered_set<string> suppliesSet(begin(supplies), end(supplies));
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegree;
    queue<string> q;

    // build graph
    for (int i = 0; i < recipes.size(); ++i)
      for (const auto& ingredient : ingredients[i])
        if (!suppliesSet.count(ingredient)) {
          graph[ingredient].push_back(recipes[i]);
          ++inDegree[recipes[i]];
        }

    // topology
    for (const auto& recipe : recipes)
      if (!inDegree.count(recipe))
        q.push(recipe);

    while (!q.empty()) {
      const auto u = q.front();
      q.pop();
      ans.push_back(u);
      if (!graph.count(u))
        continue;
      for (const auto& v : graph[u])
        if (--inDegree[v] == 0)
          q.push(v);
    }

    return ans;
  }
};
