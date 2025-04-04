class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    for (int i = left; i <= right; ++i) {
      bool seen = false;
      for (const vector<int>& range : ranges)
        if (i >= range[0] && i <= range[1]) {
          seen = true;
          break;
        }
      if (!seen)
        return false;
    }

    return true;
  }
};
