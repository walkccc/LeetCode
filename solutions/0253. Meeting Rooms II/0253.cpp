class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    // store end times of each room
    priority_queue<int, vector<int>, greater<>> minHeap;

    sort(begin(intervals), end(intervals));

    for (const auto& interval : intervals) {
      if (!minHeap.empty() && interval[0] >= minHeap.top())
        minHeap.pop();  // no overlap, we can reuse the same room
      minHeap.push(interval[1]);
    }

    return minHeap.size();
  }
};
