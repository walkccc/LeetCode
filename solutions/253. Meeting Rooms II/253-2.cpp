class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    int ans = 0;
    vector<int> starts;
    vector<int> ends;

    for (const vector<int>& interval : intervals) {
      starts.push_back(interval[0]);
      ends.push_back(interval[1]);
    }

    ranges::sort(starts);
    ranges::sort(ends);

    for (int i = 0, j = 0; i < n; ++i)
      if (starts[i] < ends[j])
        ++ans;
      else
        ++j;

    return ans;
  }
};
