class Solution {
 public:
  int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
    int mn = bounds[0][0];
    int mx = bounds[0][1];

    for (int i = 1; i < original.size(); ++i) {
      const int diff = original[i] - original[i - 1];
      mn = max(mn + diff, bounds[i][0]);
      mx = min(mx + diff, bounds[i][1]);
    }

    return max(0, mx - mn + 1);
  }
};
