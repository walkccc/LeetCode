class Solution {
 public:
  vector<vector<int>> findMaximalUncoveredRanges(int n,
                                                 vector<vector<int>>& ranges) {
    vector<vector<int>> ans;
    int start = 0;

    sort(ranges.begin(), ranges.end());

    for (const vector<int>& range : ranges) {
      const int l = range[0];
      const int r = range[1];
      if (start < l)
        ans.push_back({start, l - 1});
      if (start <= r)
        start = r + 1;
    }

    if (start < n)
      ans.push_back({start, n - 1});

    return ans;
  }
};
