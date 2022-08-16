class Solution {
 public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    const int n = nums.size();
    const int xors = reduce(begin(nums), end(nums), 0, bit_xor());
    vector<int> subXors(nums);
    vector<vector<int>> graph(n);
    vector<unordered_set<int>> children(n);

    for (int i = 0; i < n; ++i)
      children[i].insert(i);

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, -1, subXors, children);

    int ans = INT_MAX;

    for (int i = 0; i < edges.size(); ++i) {
      int a = edges[i][0];
      int b = edges[i][1];
      if (children[a].count(b))
        swap(a, b);
      for (int j = 0; j < i; ++j) {
        int c = edges[j][0];
        int d = edges[j][1];
        if (children[c].count(d))
          swap(c, d);
        vector<int> cands;
        if (a != c && children[a].count(c))
          cands = {subXors[c], subXors[a] ^ subXors[c], xors ^ subXors[a]};
        else if (a != c && children[c].count(a))
          cands = {subXors[a], subXors[c] ^ subXors[a], xors ^ subXors[c]};
        else
          cands = {subXors[a], subXors[c], xors ^ subXors[a] ^ subXors[c]};
        ans = min(ans, *max_element(begin(cands), end(cands)) -
                           *min_element(begin(cands), end(cands)));
      }
    }

    return ans;
  }

 private:
  pair<int, unordered_set<int>> dfs(const vector<vector<int>>& graph, int u,
                                    int parent, vector<int>& subXors,
                                    vector<unordered_set<int>>& children) {
    for (const int v : graph[u]) {
      if (v == parent)
        continue;
      const auto& [vXor, vChildren] = dfs(graph, v, u, subXors, children);
      subXors[u] ^= vXor;
      children[u].insert(begin(vChildren), end(vChildren));
    }
    return {subXors[u], children[u]};
  }
};
