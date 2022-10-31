class Solution {
 public:
  int amountOfTime(TreeNode* root, int start) {
    int ans = -1;
    const unordered_map<int, vector<int>> graph = getGraph(root);
    queue<int> q{{start}};
    unordered_set<int> seen{start};

    for (; !q.empty(); ++ans) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        if (!graph.count(u))
          continue;
        for (const int v : graph.at(u)) {
          if (seen.count(v))
            continue;
          q.push(v);
          seen.insert(v);
        }
      }
    }

    return ans;
  }

 private:
  unordered_map<int, vector<int>> getGraph(TreeNode* root) {
    unordered_map<int, vector<int>> graph;
    queue<pair<TreeNode*, int>> q{{{root, -1}}};  // (node, parent)

    while (!q.empty()) {
      const auto [node, parent] = q.front();
      q.pop();
      if (parent != -1) {
        graph[parent].push_back(node->val);
        graph[node->val].push_back(parent);
      }
      if (node->left)
        q.emplace(node->left, node->val);
      if (node->right)
        q.emplace(node->right, node->val);
    }

    return graph;
  }
};
