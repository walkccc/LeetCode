class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]
               ? edges[0][0]
               : edges[0][1];
  }
};
