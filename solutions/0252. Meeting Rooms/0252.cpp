class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(begin(intervals), end(intervals));

    for (int i = 1; i < intervals.size(); ++i)
      if (intervals[i - 1][1] > intervals[i][0])
        return false;

    return true;
  }
};
