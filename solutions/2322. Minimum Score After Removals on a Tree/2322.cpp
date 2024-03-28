class Solution {
 public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    const int n = nums.size();
    const int xors = reduce(nums.begin(), nums.end(), 0, bit_xor());
    vector<int> subXors(nums);
    vector<vector<int>> tree(n);
    vector<unordered_set<int>> children(n);

    for (int i = 0; i < n; ++i)
      children[i].insert(i);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, -1, subXors, children);

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
        ans = min(ans, ranges::max(cands) - ranges::min(cands));
      }
    }

    return ans;
  }

 private:
  pair<int, unordered_set<int>> dfs(const vector<vector<int>>& tree, int u,
                                    int parent, vector<int>& subXors,
                                    vector<unordered_set<int>>& children) {
    for (const int v : tree[u]) {
      if (v == parent)
        continue;
      const auto& [vXor, vChildren] = dfs(tree, v, u, subXors, children);
      subXors[u] ^= vXor;
      children[u].insert(vChildren.begin(), vChildren.end());
    }
    return {subXors[u], children[u]};
  }
};
