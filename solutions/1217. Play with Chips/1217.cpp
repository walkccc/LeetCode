class Solution {
 public:
  int minCostToMoveChips(vector<int>& chips) {
    vector<int> count(2);

    for (int chip : chips)
      ++count[chip % 2];

    return min(count[0], count[1]);
  }
};
