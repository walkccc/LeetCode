class ChildCost {
 public:
  ChildCost(int cost) {
    numNodes = 1;
    if (cost > 0)
      maxPosCosts.push_back(cost);
    else
      minNegCosts.push_back(cost);
  }

  void update(ChildCost childCost) {
    numNodes += childCost.numNodes;
    ranges::copy(childCost.maxPosCosts, back_inserter(maxPosCosts));
    ranges::copy(childCost.minNegCosts, back_inserter(minNegCosts));
    ranges::sort(maxPosCosts, greater<int>());
    ranges::sort(minNegCosts);
    maxPosCosts.resize(min(static_cast<int>(maxPosCosts.size()), 3));
    minNegCosts.resize(min(static_cast<int>(minNegCosts.size()), 2));
  }

  long maxProduct() {
    if (numNodes < 3)
      return 1;
    if (maxPosCosts.empty())
      return 0;
    long res = 0;
    if (maxPosCosts.size() == 3)
      res = static_cast<long>(maxPosCosts[0]) * maxPosCosts[1] * maxPosCosts[2];
    if (minNegCosts.size() == 2)
      res = max(res, static_cast<long>(minNegCosts[0]) * minNegCosts[1] *
                         maxPosCosts[0]);
    return res;
  }

 private:
  int numNodes;
  vector<int> maxPosCosts;
  vector<int> minNegCosts;
};

class Solution {
 public:
  vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    const int n = cost.size();
    vector<long long> ans(n);
    vector<vector<int>> tree(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, /*prev=*/-1, cost, ans);
    return ans;
  }

 private:
  ChildCost dfs(const vector<vector<int>>& tree, int u, int prev,
                const vector<int>& cost, vector<long long>& ans) {
    ChildCost res(cost[u]);
    for (const int v : tree[u])
      if (v != prev)
        res.update(dfs(tree, v, u, cost, ans));
    ans[u] = res.maxProduct();
    return res;
  }
};
