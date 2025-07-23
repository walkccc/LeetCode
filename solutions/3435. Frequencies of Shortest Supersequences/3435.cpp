enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  vector<vector<int>> supersequences(vector<string>& words) {
    vector<vector<int>> ans;
    const vector<pair<int, int>> edges = getEdges(words);
    const vector<int> nodes = getNodes(edges);
    const vector<int> letterToIndex = getLetterToIndex(nodes);
    vector<vector<int>> graph(nodes.size());

    for (const auto& [u, v] : edges)
      graph[letterToIndex[u]].push_back(letterToIndex[v]);

    for (const auto& doubledSubset : getMinimumSubsets(graph)) {
      vector<int> freq(26);
      for (const int letter : nodes)
        freq[letter] = 1;
      for (const int index : doubledSubset)
        freq[nodes[index]] = 2;
      ans.push_back(freq);
    }

    return ans;
  }

 private:
  // Returns a list of the minimum subsets of nodes that do not create a cycle
  // when skipped.
  vector<vector<int>> getMinimumSubsets(const vector<vector<int>>& graph) {
    const int n = graph.size();
    vector<vector<int>> res;
    for (int subsetSize = 0; subsetSize <= n; ++subsetSize) {
      vector<bool> combination(n);
      fill(combination.end() - subsetSize, combination.end(), true);
      do {
        vector<int> doubledSubset;
        for (int i = 0; i < n; ++i)
          if (combination[i])
            doubledSubset.push_back(i);
        if (!hasCycleSkipping(graph,
                              {doubledSubset.begin(), doubledSubset.end()}))
          res.push_back(doubledSubset);
      } while (next_permutation(combination.begin(), combination.end()));
      if (!res.empty())
        return res;
    }
    return res;
  }

  // Returns true if there is a cycle in the `graph` when skipping any edges
  // whose both endpoints are in `doubledSubset`.
  bool hasCycleSkipping(const vector<vector<int>>& graph,
                        const unordered_set<int>& doubledSubset) {
    vector<State> states(graph.size());
    for (int i = 0; i < graph.size(); ++i)
      if (hasCycle(graph, i, states, doubledSubset))
        return true;
    return false;
  }

  bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& states,
                const unordered_set<int>& doubledSubset) {
    if (states[u] == State::kVisiting)
      return true;
    if (states[u] == State::kVisited)
      return false;
    states[u] = State::kVisiting;
    if (!doubledSubset.contains(u))
      for (const int v : graph[u])
        if (!doubledSubset.contains(v) &&
            hasCycle(graph, v, states, doubledSubset))
          return true;
    states[u] = State::kVisited;
    return false;
  }

  vector<pair<int, int>> getEdges(const vector<string>& words) {
    vector<pair<int, int>> edges;
    for (const string& word : words)
      edges.push_back({word[0] - 'a', word[1] - 'a'});
    return edges;
  }

  vector<int> getNodes(const vector<pair<int, int>>& edges) {
    set<int> nodes;
    for (const auto& [u, v] : edges) {
      nodes.insert(u);
      nodes.insert(v);
    }
    return {nodes.begin(), nodes.end()};
  }

  vector<int> getLetterToIndex(const vector<int>& nodes) {
    vector<int> letterToIndex(26);
    for (int i = 0; i < nodes.size(); ++i)
      letterToIndex[nodes[i]] = i;
    return letterToIndex;
  }
};
