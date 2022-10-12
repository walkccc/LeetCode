class Solution {
 public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    vector<int> ans;
    unordered_map<int, vector<int>> tree;

    for (int i = 0; i < pid.size(); ++i) {
      if (ppid[i] == 0)
        continue;
      tree[ppid[i]].push_back(pid[i]);
    }

    dfs(tree, kill, ans);
    return ans;
  }

 private:
  void dfs(const unordered_map<int, vector<int>>& tree, int u,
           vector<int>& ans) {
    ans.push_back(u);
    if (!tree.count(u))
      return;
    for (const int v : tree.at(u))
      dfs(tree, v, ans);
  }
};
