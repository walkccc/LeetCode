class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    vector<int> count(2);
    for (const int p : position)
      ++count[p % 2];
    return min(count[0], count[1]);
  }
};
