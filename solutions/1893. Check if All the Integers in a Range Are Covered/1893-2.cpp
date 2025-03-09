class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> seen(52);

    for (const vector<int>& range : ranges) {
      ++seen[range[0]];
      --seen[range[1] + 1];
    }

    for (int i = 1; i < 52; ++i)
      seen[i] += seen[i - 1];

    for (int i = left; i <= right; ++i)
      if (!seen[i])
        return false;

    return true;
  }
};
