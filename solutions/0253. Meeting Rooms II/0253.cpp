class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty())
      return 0;

    // store end times of each room
    priority_queue<int, vector<int>, greater<>> pq;

    sort(begin(intervals), end(intervals));

    for (const auto& interval : intervals) {
      if (!pq.empty() && interval[0] >= pq.top())
        pq.pop();  // no overlap, we can reuse the same room
      pq.push(interval[1]);
    }

    return pq.size();
  }
};
