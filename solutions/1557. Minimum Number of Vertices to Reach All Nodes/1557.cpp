class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> ans;
    vector<int> inDegrees(n);

    for (const vector<int>& edge : edges)
      ++inDegrees[edge[1]];

    for (int i = 0; i < inDegrees.size(); ++i)
      if (inDegrees[i] == 0)
        ans.push_back(i);

    return ans;
  }
};
