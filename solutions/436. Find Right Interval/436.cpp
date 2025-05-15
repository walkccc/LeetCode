class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> ans;
    map<int, int> startToIndex;

    for (int i = 0; i < intervals.size(); ++i)
      startToIndex[intervals[i][0]] = i;

    for (const vector<int>& interval : intervals) {
      const auto it = startToIndex.lower_bound(interval[1]);
      ans.push_back(it == startToIndex.cend() ? -1 : it->second);
    }

    return ans;
  }
};
