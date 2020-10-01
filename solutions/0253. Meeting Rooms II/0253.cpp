class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    auto compare = [](const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

    sort(begin(intervals), end(intervals));
    pq.push(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
      const vector<int>& interval = intervals[i];
      vector<int> earliestAvailable = pq.top(); pq.pop();
      if (intervals[i][0] >= earliestAvailable[1])
        earliestAvailable[1] = interval[1];
      else
        pq.push(interval);
      pq.push(earliestAvailable);
    }

    return pq.size();
  }
};