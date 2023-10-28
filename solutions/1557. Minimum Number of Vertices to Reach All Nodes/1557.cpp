class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> ans;
    vector<int> inDegree(n);

    for (const vector<int>& edge : edges)
      ++inDegree[edge[1]];

    for (int i = 0; i < inDegree.size(); ++i)
      if (inDegree[i] == 0)
        ans.push_back(i);

    return ans;
  }
};
