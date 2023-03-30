class Solution {
 public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                     vector<int>& toBeRemoved) {
    vector<vector<int>> ans;

    for (const vector<int>& interval : intervals) {
      const int a = interval[0];
      const int b = interval[1];
      if (a >= toBeRemoved[1] || b <= toBeRemoved[0]) {
        ans.push_back(interval);
      } else {  // a < toBeRemoved[1] && b > toBeRemoved[0]
        if (a < toBeRemoved[0])
          ans.push_back({a, toBeRemoved[0]});
        if (b > toBeRemoved[1])
          ans.push_back({toBeRemoved[1], b});
      }
    }

    return ans;
  }
};
