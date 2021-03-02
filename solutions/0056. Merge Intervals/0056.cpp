class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    sort(begin(intervals), end(intervals));

    for (const auto& interval : intervals)
      if (ans.empty() || ans.back()[1] < interval[0])
        ans.push_back(interval);
      else
        ans.back()[1] = max(ans.back()[1], interval[1]);

    return ans;
  }
};
