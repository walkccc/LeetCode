class Solution {
 public:
  int minCost(vector<int>& startPos, vector<int>& homePos,
              vector<int>& rowCosts, vector<int>& colCosts) {
    int ans = 0;
    int i = startPos[0];
    int j = startPos[1];
    int x = homePos[0];
    int y = homePos[1];

    while (i != x)
      ans += i < x ? rowCosts[++i] : rowCosts[--i];
    while (j != y)
      ans += j < y ? colCosts[++j] : colCosts[--j];

    return ans;
  }
};
