class Solution {
 public:
  bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                              vector<vector<string>>& pairs) {
    if (words1.size() != words2.size())
      return false;

    // graph[key] := all the similar words of key
    unordered_map<string, unordered_set<string>> graph;

    for (const vector<string>& pair : pairs) {
      graph[pair[1]].insert(pair[0]);
      graph[pair[0]].insert(pair[1]);
    }

    for (int i = 0; i < words1.size(); ++i) {
      if (words1[i] == words2[i])
        continue;
      if (!graph.count(words1[i]))
        return false;
      if (!dfs(graph, words1[i], words2[i], {}))
        return false;
    }

    return true;
  }

 private:
  bool dfs(const unordered_map<string, unordered_set<string>>& graph,
           const string& source, const string& target,
           unordered_set<string>&& seen) {
    if (graph.at(source).count(target))
      return true;

    seen.insert(source);

    for (const string& child : graph.at(source)) {
      if (seen.count(child))
        continue;
      if (dfs(graph, child, target, move(seen)))
        return true;
    }

    return false;
  }
};
