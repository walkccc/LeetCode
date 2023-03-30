class Solution {
 public:
  int countHighestScoreNodes(vector<int>& parents) {
    int ans = 0;
    vector<vector<int>> tree(parents.size());

    for (int i = 0; i < parents.size(); ++i) {
      if (parents[i] == -1)
        continue;
      tree[parents[i]].push_back(i);
    }

    dfs(tree, 0, 0, ans);
    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& tree, int u, long&& maxScore, int& ans) {
    int count = 1;
    long score = 1;
    for (const int v : tree[u]) {
      const int childCount = dfs(tree, v, move(maxScore), ans);
      count += childCount;
      score *= childCount;
    }
    const int aboveCount = tree.size() - count;
    score *= max(aboveCount, 1);
    if (score > maxScore) {
      maxScore = score;
      ans = 1;
    } else if (score == maxScore) {
      ++ans;
    }
    return count;
  }
};
