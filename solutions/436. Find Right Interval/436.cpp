class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> ans;
    map<int, int> startToIndex;

    for (int i = 0; i < intervals.size(); ++i)
      startToIndex[intervals[i][0]] = i;

    for (const vector<int>& interval : intervals) {
      const auto it = startToIndex.lower_bound(interval[1]);
      if (it == startToIndex.cend())
        ans.push_back(-1);
      else
        ans.push_back(it->second);
    }

    return ans;
  }
};
